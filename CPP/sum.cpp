#include <iostream>

using namespace std;

int main()
{
    size_t T;
    cin>>T;
    int a;
    int b;
    int c[T];
    for (size_t i =0; i!=T; ++i){
        cin>>a;
        cin>>b;
        c[i] = a+b;
    }
    for (auto el:c){
        cout<<el<<endl;
    }
}