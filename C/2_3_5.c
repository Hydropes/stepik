#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <malloc.h>

/* Вы можете пользоваться следующими определениями:

struct maybe_int64 {int64_t value; bool valid;};
struct maybe_int64 some_int64(int64_t i);
const struct maybe_int64 none_int64 = { 0, false };
void maybe_int64_print( struct maybe_int64 i );


struct array_int {int64_t* data; size_t size;};
struct array_int array_int_create( size_t sz );
*/




//Helping funcs
struct maybe_int64 {
  int64_t value;
  bool valid;
};

const struct maybe_int64 none_int64 = { 0 };

struct array_int {
  int64_t* data;
  size_t size;
};

struct maybe_int64 some_int64(int64_t i) {
  return (struct maybe_int64) { i, true };
}


void print_int64(int64_t i){
    printf("%"PRId64, i);
}

void array_int_free( struct array_int a ) {
    if ( a.size > 0 ) {
        free(a.data);
        a.size = 0;
    }
}

// возвращает ошибку если индекс за пределами массива
struct maybe_int64 array_int_get( struct array_int a, size_t i ) {
  if(i>=a.size|| i<0){
    return none_int64;
  }
  return some_int64(a.data[i]);
}

// возвращает false если индекс за пределами массива
bool array_int_set( struct array_int a, size_t i, int64_t value ) {
  if(i>=a.size|| i<0){
    return false;
  }
  a.data[i]=value;
  return true;
}



//new funcs:
struct array_int array_int_create( size_t sz ) {
    return (struct array_int) { .data = malloc( sizeof( int64_t ) * sz ), .size = sz };
}

struct stack {
  size_t count;
  struct array_int data;
};

// Количество элементов в стеке
size_t stack_count( const struct stack* s ){
    return s->count;
}

// Создаем и деинициализируем стек
struct stack stack_create( size_t size ){
    struct stack new_stack = {.count =0, .data = array_int_create(size)};
    return new_stack;
}

void stack_destroy( struct stack* s ){
    s->count =0;
    array_int_free(s->data);
}

// Стек полный
bool stack_is_full( const struct stack * s){
    if (s->count == s->data.size){return true;}
    return false;
}
// Стек пустой
bool stack_is_empty( const struct stack * s){
    if (s->count == 0){return true;}
    return false;
};

// Поместить значение в стек
bool stack_push( struct stack* s, int64_t value ){
    if (!stack_is_full(s)){
       s->count+=1;
       return array_int_set(s->data, s->count-1, value);
    }
    return false;
}

// Вынуть значение с вершины стека. Может вернуть none_int64
struct maybe_int64 stack_pop( struct stack* s ){
    if(!stack_is_empty(s)){
       struct maybe_int64 el = array_int_get(s->data, s->count-1);
       s->data.data[s->count-1]=0;
       s->count-=1;
       return el;
    }
    return none_int64;
}

void stack_print( const struct stack* s ) {
  for (size_t i = 0; i < stack_count( s ); i = i + 1 ) {
    print_int64( array_int_get( s->data, i).value );
    printf(" ");
  }
}

int main(){
    //print_int64(1);
    struct stack new_stack = stack_create(10);
    printf("full = %d\n", stack_is_full(&new_stack));
    printf("empty = %d\n", stack_is_empty(&new_stack));
    printf("count = %d\n", new_stack.count);
    for(int64_t i =0; i<new_stack.data.size; i++){
        stack_push(&new_stack, i);
    }
    printf("pop = %d\n", stack_pop(&new_stack).value);
    printf("count = %d\n", new_stack.count);
    printf("full = %d\n", stack_is_full(&new_stack));
    stack_print(&new_stack);
    stack_destroy(&new_stack);
    stack_print(&new_stack);
}

