#include <iostream>

using namespace std;

char * getline(){
    int size = 2;
    int len =0;
    char *m = new char[size];
    char c= '\0';
    while(!cin.eof()&&c!='\n'){
        if(len==size-1){
           char *new_m = new char[2*size];
           copy(m,m+size, new_m);
           delete [] m;
           m = new_m;
           size*=2;
        } 
        m[len]=c;
        ++len;
        c=cin.get();  
    }
    m[len]='\0';
    return m;
}

int main()
{
    cout<<getline();
    return 0;
}