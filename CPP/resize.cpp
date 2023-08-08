#include <iostream>

using namespace std;

char * resize(const char *str, unsigned size, unsigned new_size){
    
    char *m = new char[new_size];
    cout<<sizeof(m)<<'\n';
    unsigned real_size = size<new_size?size:new_size;
    for (size_t i=0; i<real_size; ++i){
        m[i]=str[i];
    }
    cout<<sizeof(m)<<'\n';
    return m;
}

int main()
{
    char str[] = "aaaa";
    //cout<<sizeof(str)<<'\n';
    char *m = resize(str, 5, 100);
    return 0;
}