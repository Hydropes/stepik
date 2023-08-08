#include <iostream>

using namespace std;

unsigned gcd(unsigned a, unsigned b){
    if (b>a){
        unsigned min = a;
        a=b;
        b=min;
    }
    if (b==0){
        return a;
    }
    return gcd(b, a%b);
}

int main()
{
   cout<<gcd(100, 300)<<"\n";
}