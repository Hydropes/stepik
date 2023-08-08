#include <stdio.h>
#include <malloc.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

size_t read_size(){
    size_t p =0;
    scanf("%d", &p);
    return p;
}

int64_t read_int64(){
    int64_t p =0;
    scanf("%"SCNd64, &p);
    return p;
}

void array_int_fill(int64_t* array, size_t size){
    for(size_t i=0; i<size; i++){
        array[i] = read_int64();
    }

}
int64_t* array_int_read(size_t* size){
    *size = read_size();
    //printf("size = %d\n", *size);
    int64_t * array = malloc(sizeof(int64_t)*(*size));
    array_int_fill(array, *size);
    return array;
}


void array_int_print(int64_t* array, size_t size){
    for(size_t  i = 0; i<size; i++){
        printf("%"PRId64" ", array[i]);
    }

}

int64_t* array_int_min(int64_t* array, size_t size){
    if (size ==0){
        return NULL;
    }
    int64_t min = pow(2, 64)-1;
    int64_t *ptr_ret =array;
    for(int64_t *ptr =array; ptr<array+size; ptr++){
        if(*ptr<min){
            ptr_ret = ptr;
            min = *ptr;
        }
    }
    return ptr_ret;
}

int64_t** marray_read(size_t* rows, size_t** sizes){
    *rows =read_size();
    *sizes = (size_t*)malloc(*rows*sizeof(size_t));
    int64_t** marray = malloc(*rows*sizeof(int64_t*));
    for(size_t i =0; i<*rows; i++){
        marray[i] =array_int_read(*sizes+i);
    }
    return marray;
}

void marray_print(int64_t** marray, size_t* sizes, size_t rows){
    for(size_t  i = 0; i<rows; i++){
        array_int_print(marray[i], sizes[i]);
        printf("\n");
    }
}

void marray_free(int64_t** marray, size_t rows){
    for (size_t i = 0; i<rows; i++){
        free(marray[i]);
    }
}

int64_t* int64_ptr_min(int64_t* x, int64_t* y){
    int64_t* min;
    if(x==NULL&&y==NULL){
        return NULL;
    }else if(x!=NULL&&y==NULL){
        min=x;
    }else if (x==NULL&&y!=NULL){
        min = y;
    }else{
        if (*x<*y){
            min =  x;
        }else{
            min = y;
        }
    }
    return min;
}

int64_t * marray_int_min(int64_t** marray, size_t* sizes, size_t rows){
    if (rows ==0){
        return NULL;
    }
    int64_t *ptrs = malloc(rows*sizeof(int64_t));
    int64_t *ptr_min = marray[0];
    for(size_t i = 0; i<rows; i++){
        ptrs[i] = array_int_min(marray[i], sizes[i]);
    }
    for(size_t i = 0; i<rows; i++){
        ptr_min = int64_ptr_min(ptr_min, ptrs[i]);
    }
    return ptr_min;
    //return ptrs[1];
}

void marray_normalize(int64_t** marray, size_t sizes[], size_t rows, int64_t m){
    for(size_t i =0; i<rows; i++){
        for(size_t j = 0; j<sizes[i]; j++){
            marray[i][j]-=m;
        }
    }
}

void perform(){
    size_t rows;
    size_t* sizes;
    int64_t** marray = marray_read(&rows, &sizes);
    int64_t* min = marray_int_min(marray, sizes, rows);
    marray_normalize(marray, sizes, rows, *min);
    marray_print(marray, sizes, rows);
    marray_free(marray, rows);
}



int main(){

    //int64_t *arr;
    //size_t size;

    //arr = array_int_read(&size);
    //array_int_print(arr, size);

    //int64_t** marray;
    //size_t rows;
    //size_t *sizes;
    //marray = marray_read(&rows, &sizes);



    //int64_t* min = marray_int_min(marray, sizes, rows);
    //marray_normalize(marray, sizes, rows, *min);
    //marray_print(marray, sizes, rows);
    //printf("min = %"PRId64"\n", *min);

    //int64_t x = 10;
    //int64_t y =20;
    //printf("min_test = %"PRId64"\n", *int64_ptr_min(&x, &y));

    //marray_free(marray, rows);
    perform();


}

