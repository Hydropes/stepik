#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include <malloc.h>

/* Вы можете пользоваться этими функциями из предыдущих заданий */
/*size_t read_size() { size_t i; scanf("%zu", &i); return i; }

void array_int_fill( int64_t* array, size_t sz );

struct array_int array_int_read();
struct maybe_int64 array_int_get( struct array_int a, size_t i );
bool array_int_set( struct array_int a, size_t i, int64_t value );
void array_int_print( struct array_int array );
struct maybe_int64 array_int_min( struct array_int array );
void array_int_free( struct array_int a );

void array_int_normalize( struct array_int array, int64_t m ) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    array.data[i] = array.data[i] - m;
  }
}*/



/*  ---- HELPING STRUCT ---- */
int read_size() { int i; scanf("%d", &i); return i; }
size_t read_int64() { size_t i; scanf("%"SCNd64, &i); return i; }


struct maybe_int64 {
  int64_t value;
  bool valid;
};

const struct maybe_int64 none_int64 = { 0 };

struct array_int {
  int64_t* data;
  size_t size;
};

//возвращает структуру из числа
struct maybe_int64 some_int64(int64_t i) {
  return (struct maybe_int64) { i, true };
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


void array_int_fill( int64_t* array, size_t sz ) {
  for( size_t i = 0; i < sz; i = i + 1 ) {
    array[i] = read_int64();
  }
}

struct array_int array_int_read() {
  const size_t size = read_size();
  if (size > 0) {
    int64_t* array = malloc( sizeof(int64_t) * size);
    array_int_fill( array, size );
    return (struct array_int) { .data = array, .size = size };
  }
  else return (struct array_int) {0};
}

void array_int_print( struct array_int array ) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    printf("%" PRId64 " " , array_int_get( array, i).value);
  }
}

struct maybe_int64 array_int_min( struct array_int array ) {
    struct maybe_int64 min =some_int64(1000000);
        for(size_t i =0; i<array.size; i++){
            if(array.data[i]<min.value){
                min = some_int64(array.data[i]);
            }
        }
        return min;
}

void array_int_free( struct array_int a ) {
    if ( a.size > 0 ) {
        free(a.data);
        a.size = 0;
    }
}

void array_int_normalize( struct array_int array, int64_t m ) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    array.data[i] = array.data[i] - m;
  }
}


/*  ---- maybe int[] ---- */



struct maybe_array_int {
  struct array_int value;
  bool valid;
};

//возвращает структуру maybe_array_int из массива
struct maybe_array_int some_array_int(struct array_int array) {
  return (struct maybe_array_int) { array, true };
}
const struct maybe_array_int none_array_int = { {NULL, 0}, false };


/*  ---- int[][] ---- */

struct array_array_int {
  struct array_int* data;
  size_t size;
};

/*  --- строки ---  */

struct maybe_array_int array_array_int_get_row( struct array_array_int a, size_t i ) {
  if ( 0 <= i && i < a.size ) { return some_array_int( a.data[i] ); }
  else { return none_array_int; }
}

bool array_array_int_set_row( struct array_array_int a, size_t i, struct array_int value ) {
  if (0 <= i && i < a.size) {
    a.data[i] = value;
    return true;
  }
  else { return false; }
}

/*  --- get/set ---  */

struct maybe_int64 array_array_int_get( struct array_array_int a, size_t i, size_t j ) {
 struct maybe_array_int row = array_array_int_get_row(a, i);
 if (row.valid){
    struct maybe_int64 val = array_int_get(row.value, j);
    if(val.valid){
        return  val;
    }
 }
 return none_int64;
}

bool array_array_int_set( struct array_array_int a, size_t i, size_t j, int64_t value ) {
    struct maybe_array_int row =array_array_int_get_row(a, i);
        if(row.valid){
            if(array_int_set(row.value, j, value)){
                return true;
            }
        }
    return false;
}

/*  --- read/print ---  */

struct array_array_int array_array_int_read() {
    struct array_array_int array ={.data =NULL, .size=0};
    size_t size = read_size();

    if(size>0){

        array.data = malloc(size*sizeof(struct array_int));
        array.size = size;
        for (size_t i =0; i<array.size; i++){
            array.data[i] = array_int_read();
        }
    }
    return array;

}

    //for(size_t i =0; i<array.size; i++){
        //array_int_print(array.data[i]);
        //printf("\n");
    //}

void array_array_int_print( struct array_array_int array) {

    for(size_t i =0; i<array.size; i++){
       for(size_t j =0; j<array.data[i].size; j++){
           printf("%" PRId64 " " , array_array_int_get( array, i, j).value);
       }
        printf("\n");
    }
}

/*  --- min/normalize ---  */

// найти минимальный элемент в массиве массивов
struct maybe_int64 array_array_int_min( struct array_array_int array ) {
    struct maybe_int64 min =none_int64;
    for(size_t i =0; i<array.size; i++){
        if(array.data[i].size>0){
            min =some_int64(array_array_int_get(array, i, 0).value);
            break;
        }
    }

    if (array.size>0){
        for(size_t i =0; i<array.size; i++){
            if(array.data[i].size>0){
                struct maybe_int64 row_min = array_int_min(array.data[i]);
                if (row_min.value<min.value){
                    min.value = row_min.value;
                }
            }

        }
        return min;
    }
    return none_int64;
}

// вычесть из всех элементов массива массивов число m
void array_array_int_normalize( struct array_array_int array, int64_t m) {
  for (size_t i = 0; i < array.size; i = i + 1) {
    const struct maybe_array_int cur_row = array_array_int_get_row( array, i );
    if (cur_row.valid) {
         array_int_normalize( cur_row.value, m );
    }
  }
}

void array_array_int_free( struct array_array_int array ) {
  for(size_t i = 0; i<array.size; i++){
    array_int_free(array.data[i]);
    free(array.data[i].size);
  }
  free(array.data);
  array.size = 0;
}



void perform() {
  struct array_array_int array = array_array_int_read();
  struct maybe_int64 m = array_array_int_min( array );
  if (m.valid) {
    array_array_int_normalize( array, m.value );
    array_array_int_print( array );
  }
  array_array_int_free( array );
}

int main(){
    //struct array_array_int A = array_array_int_read();
    //printf("Our array: \n");
    //array_array_int_print(A);
    //struct maybe_int64 min = array_array_int_min(A);
    //printf("Our min = %d", min.value);
    //array_array_int_normalize(A, min.value);
    //printf("Our new array: \n");
    //array_array_int_print(A);
    perform();
}
