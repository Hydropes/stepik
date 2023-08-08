#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <malloc.h>
#include <stdbool.h>

struct stack{
   int64_t value;
   struct stack* next;
};

struct maybe_int64
{
  int64_t value;
  bool valid;
};

struct vm_state {
  const union ins *ip;
  struct stack data_stack;
};

enum opcode { BC_PUSH, BC_IPRINT, BC_IREAD, BC_IADD, BC_STOP };

struct bc_noarg {
  enum opcode opcode;
};
struct bc_arg64 {
  enum opcode opcode;
  int64_t arg;
};
union ins {
  enum opcode opcode;
  struct bc_arg64 as_arg64;
  struct bc_noarg as_noarg;
};

struct maybe_int64 some_int64(int64_t i);

extern const struct maybe_int64 none_int64;

void maybe_int64_print( struct maybe_int64 i );
struct maybe_int64 maybe_read_int64();



/* Вы можете использовать эти функции: */
void print_int64(int64_t val);
struct maybe_int64 maybe_read_int64();

struct stack stack_create(size_t size);
void stack_destroy(struct stack *s);
bool stack_push(struct stack *s, int64_t value);
struct maybe_int64 stack_pop(struct stack *s);


void lift_unop(struct stack* s, int64_t(f)(int64_t)){
  int64_t val = stack_pop(s).value;
  int64_t res = f(val);
  stack_push(s, res);
}

void lift_binop(struct stack* s, int64_t(f)(int64_t,  int64_t)){
  int64_t b = stack_pop(s).value;
  int64_t a = stack_pop(s).value;
  int64_t res = f(a, b);
  stack_push(s, res);
}

void interpret_push(struct vm_state* state) {
  stack_push(&state->data_stack, state->ip->as_arg64.arg);
}

void interpret_iread(struct vm_state* state ) {
  struct maybe_int64 val3 = maybe_read_int64();
                stack_push(&state->data_stack, val3.value) ;
                
}
void interpret_iadd(struct vm_state* state ) {
  struct maybe_int64 val1 = stack_pop(&state->data_stack);
                struct maybe_int64 val2 = stack_pop(&state->data_stack);
                stack_push(&state->data_stack, val1.value+val2.value);
}
void interpret_iprint(struct vm_state* state ) {
  struct maybe_int64 val = stack_pop(&state->data_stack);
                print_int64(val.value);
}


/* Подсказка: можно выполнять программу пока ip != NULL,
    тогда чтобы её остановить достаточно обнулить ip */
void interpret_stop(struct vm_state* state ) {
  state->ip=0;
}

void interpret_swap(struct vm_state* state){
 struct maybe_int64 b = stack_pop(&state->data_stack);
  struct maybe_int64 a = stack_pop(&state->data_stack);
  stack_push(&state->data_stack, b.value);
  stack_push(&state->data_stack, a.value);
}

void interpret_pop(struct vm_state* state){
  stack_pop(&state->data_stack);
}

void interpret_dup(struct vm_state* state){
  struct maybe_int64 a = stack_pop(&state->data_stack);
  stack_push(&state->data_stack, a.value);
  stack_push(&state->data_stack, a.value);
}

void (*interpreters[5])(struct vm_state*)= {
  [BC_PUSH] = interpret_push,
  [BC_IPRINT] = interpret_iprint,
  [BC_IREAD] = interpret_iread,
  [BC_IADD] =interpret_iadd,  
  [BC_STOP] = interpret_stop,
};

void interpret(struct vm_state* state) {
  while(state->ip!=NULL){
    
    interpreters[state->ip->opcode](state);
    if(state->ip!=NULL){state->ip+=1;};
  }
}