#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>

/* �� ������ ������������ ����� ��������� �� ���������� ������� */
size_t read_size() { size_t i; scanf("%zu", &i); return i; }

void array_int_fill( int64_t* array, size_t sz );

struct array_int array_int_read();
struct maybe_int64 array_int_get( struct array_int a, size_t i );
bool array_int_set( struct array_int a, size_t i, int64_t value );
void array_int_print( struct array_int array );
struct maybe_int64 array_int_min( struct array_int array );
void array_int_free( struct array_int a );



/*  ---- maybe int[] ---- */
struct array_int {
  int64_t* data;
  size_t size;
};

struct maybe_int64 {
  bool valid;
  int64_t value;
};


struct maybe_array_int {
  struct array_int value;
  bool valid;
};



struct maybe_array_int some_array_int(struct array_int array) {
  return (struct maybe_array_int) { array, true };
}
const struct maybe_array_int none_array_int = { {NULL, 0}, false };


/*  ---- int[][] ---- */

struct array_array_int {
  struct array_int* data;
  size_t size;
};

/*  --- ������ ---  */

struct maybe_array_int array_array_int_get_row( struct array_array_int a, size_t i ) {
  if ( 0 <= i && i < a.size ) {
        return some_array_int( a.data[i] );
  }
  else
    { return none_array_int; }
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
    struct maybe_array_int mb_array = array_array_int_get_row(a,i);
    struct maybe_int64 mb_int64 =array_int_get(mb_array.value, j);
    return mb_int64;
   // return none_int64;

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
    perform();
    printf("aaaa");
}
