#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define STACK_CAPACITY 10

struct maybe_int64
{
    bool valid;
    int64_t value;
};

struct stack stack_create(size_t size);
void stack_destroy(struct stack *s);
bool stack_push(struct stack *s, int64_t value);
struct maybe_int64 stack_pop(struct stack *s);

struct array_int
{
    int64_t *data;
    size_t size;
};

// struct array_int array_int_create(size_t sz)
// {
//     return (struct array_int){.data = (int64_t*)malloc(sizeof(int64_t) * sz), .size = sz};
// }

struct stack
{
    int64_t value;
    struct stack *next;
};


/* Описание инструкций (см. предыдущий шаг) */
enum opcode
{
    BC_PUSH,
    BC_IPRINT,
    BC_IREAD,
    BC_IADD,
    BC_STOP
};

struct bc_noarg
{
    enum opcode opcode;
};
struct bc_arg64
{
    enum opcode opcode;
    int64_t arg;
};
union ins
{
    enum opcode opcode;
    struct bc_arg64 as_arg64;
    struct bc_noarg as_noarg;
};

/* ------------------------ */

struct vm_state
{
    const union ins *ip;
    struct stack data_stack;
};

/* Начальная вместимость стека задаётся определением STACK_CAPACITY */
struct vm_state state_create(const union ins *ip)
{
    return (struct vm_state){.ip = ip,
                             .data_stack = stack_create(STACK_CAPACITY)};
}

// Как правильно деинициализировать состояние, освободить все ресурсы?
void state_destroy(struct vm_state *state)
{
    stack_destroy(&state->data_stack);
}

/* Вы можете использовать эти функции: */
void print_int64(int64_t);
struct maybe_int64 maybe_read_int64();

// struct stack stack_create(size_t size);
// void stack_destroy(struct stack *s);
// bool stack_push(struct stack *s, int64_t value);
// struct maybe_int64 stack_pop(struct stack *s);

/* Опишите цикл интерпретации с выборкой и выполнением команд (пока не выполним STOP) */
void interpret(struct vm_state *state)
{
    while(1){
        switch (state->ip->opcode)
        {
        case BC_PUSH:
           { 
            stack_push(&state->data_stack, state->ip->as_arg64.arg);
            break;
            }
        case BC_IPRINT:
            {
                struct maybe_int64 val = stack_pop(&state->data_stack);
                print_int64(val.value);
                break;
            }
        case BC_IREAD:
            {
                struct maybe_int64 val3 = maybe_read_int64();
                stack_push(&state->data_stack, val3.value) ;
                break;
            }
        case BC_IADD:
            {
                struct maybe_int64 val1 = stack_pop(&state->data_stack);
                struct maybe_int64 val2 = stack_pop(&state->data_stack);
                stack_push(&state->data_stack, val1.value+val2.value);
                break;
            }
        case BC_STOP: return;
            
        default:
            break;
        }
        state->ip = state->ip + 1;
    }
}

void interpret_program(const union ins *program)
{
    struct vm_state state = state_create(program);
    interpret(&state);
    state_destroy(&state);
}

int main(){

}