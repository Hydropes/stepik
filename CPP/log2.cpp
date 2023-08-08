#include <iostream>

using namespace std;

int log2(int n){
    int res = 0;
    int i = 2;
    while(i<=n){
        res++;
        i*=2;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    int p[t];
    for (size_t i =0; i!=t; ++i){
        cin>>p[i];
    }
    cout<<endl;
    for(auto el:p){
        cout <<log2(el)<<"\n";
    }
}