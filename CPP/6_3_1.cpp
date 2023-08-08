#include <cstddef>

template<typename T, typename U>
void copy_n(T* to, U const& from, size_t size){
    for (size_t i = 0; i < size; i++)
    {
        to[i] = (T)from[i];
    }    
}

int main(){
    int ints[] = {1, 2, 3, 4};
    double doubles[4]={};
    copy_n(doubles, ints, 4);
}