#include <iostream>

using namespace std;

struct Cls
{
    Cls(char c, double d, int i){
        this->c = c;
        //cout<<&c<<endl;
        this->d = d;
        //cout<<&d<<endl;
    };
public:
char get_c(){
    return this->c;
}
private:
    char c;
    double d;
    int i;
};

char &get_c(Cls &cls){
    char * a = (char *)&cls;
    *a ='c';
    cout<<a<<endl;
    return *a;
}

int &get_i(Cls &cls){
    int * a = (int*)((char *)&cls+4);
    cout<<*a<<endl;
    return *a;
}

double &get_d(Cls &cls){
    double * a = (double*)((char *)&cls+8);
    cout<<*a<<endl;
    return *a;
}


int main()
{
    Cls cls1('b', 1., 2);
    get_c(cls1);
    get_i(cls1);
    get_d(cls1);
    cout<<cls1.get_c()<<'\n';
    return 0;
}