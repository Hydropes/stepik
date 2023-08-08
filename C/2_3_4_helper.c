//another version of func

struct array_array_int array_array_int_read() {
    struct array_array_int Array_array ={.data =NULL, .size=0};
    size_t size = read_size();
    if(!size){
        printf("AAAA");
        return Array_array;
    }
    Array_array.data = malloc(size*sizeof(struct array_int));
    Array_array.size = size;
    printf("Array size = %d", Array_array.size);
    for(size_t i =0; i<Array_array.size; i++){
        size = read_size();
        printf("curr size = %d", size);
        if(size==0){
            printf("here 1\n");
            Array_array.data[i].data =NULL;
            Array_array.data[i].size = 0;
        }else{
            printf("here 2\n");
            Array_array.data[i].data =malloc(size*sizeof(int64_t));
            Array_array.data[i].size = size;
             for(size_t j =0; j<Array_array.data[i].size; j++){
                 scanf("%"SCNd64, &Array_array.data[i].data[j]);
             }
        }

    }
    return Array_array;
}
