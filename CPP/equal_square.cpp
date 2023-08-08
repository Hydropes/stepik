#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    double D, x1, x2;
    D = b*b - 4*a*c;
    if (D>0){
        x1 = (-b+sqrt(D))/(2*a);
        x2 = (-b-sqrt(D))/(2*a);
        cout<<x1<<"\n";
        cout<<x2<<"\n";
    }else if(D==0){
        cout<<-b/(2*a)<<"\n";
    }else{
        cout<<"No real roots"<<"\n";
    }

}