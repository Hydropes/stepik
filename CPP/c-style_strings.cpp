#include <iostream>

using namespace std;

unsigned strlen(const char *str){
    size_t l = 0;
    while(*str){
        l++;
        *str++;
    }
    return l;
}

void strcat(char *to,  const char *from){
    const int len =strlen(to);
    for (int i = strlen(to); i<strlen(to)+strlen(from); ++i){
        to[i]=from[i-len];
    }
    to[strlen(to)+strlen(from)]= '\0';

}

int strstr(const char *text, const char *pattern){
    if(strlen(pattern)==0){
        return 0;
    }
    int point =-1;
    const int len = strlen(pattern);
    
    for(int i=0; i<strlen(text); ++i){
        int counter =0;
        for (int j =0; j<strlen(pattern); ++j){
            if (text[i+j]==pattern[j]){
                cout<< text[i+j]<<'\n';
                counter++;
            }
       }
       if (counter==len){
            return i;
       }
    }
    cout<<endl;
    return point;
}




int main()
{
    // cout<<strlen("aaa fff")<<endl;

    // char uno[] = "aaa";
    // char dos[] = "bbbbb";
    // strcat(uno, dos);
    // cout<<uno<<'\n';

    char text[] = "c-style strings";
    char text2[] = "";
    char pattern[] = "sty";
    cout<<strstr(text, pattern)<<'\n';


}