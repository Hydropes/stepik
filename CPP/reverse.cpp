#include <iostream>

using namespace std;

void reverse(){
    char c ='\0';
    cin.get(c);
    if (c!='0'){
       
       reverse(); 
       cout<<c;
    }
    
}

int main()
{
    reverse();
}