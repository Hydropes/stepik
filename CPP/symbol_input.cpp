#include <iostream>

using namespace std;

int main()
{
    // char c ='\0';
    // while(cin.get(c)){
    //     if (c!='a'){
    //         cout<<c;
    //     }
    // }
    // cout<<"That's all"<<"\n";
    char c='\0';
    while(!cin.eof()){
        cin.get(c);
        char b= cin.peek();
        if(c==' '&& b ==' '){
            cin.get(c);
            
        }
        cout<<c;
        // cout<<b<<"\n";
    }
    cout<<"\n";
}