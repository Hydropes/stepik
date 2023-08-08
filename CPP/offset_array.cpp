#include <iostream>

using namespace std;

void rotate( int a[], unsigned size, int shift){
    if (shift>0){
        if (shift>1){
        rotate(a, size, shift-1);
    } 
    int temp = a[size-1];
    for (int i =size-1; i>0; i--){
        a[i]= a[(size-1+i)%size];
        // cout<<"a = "<<a[i]<<endl;
    }
    a[0] = temp;
    }
    }
    
    


int main()
{
    unsigned size =4;
    int a[size] = {1, 3, 4, 7};
    rotate(a, 4, 0);
    for (auto el: a){
        cout<<el<<" ";
    }
    cout<<endl;
    return 0;
}