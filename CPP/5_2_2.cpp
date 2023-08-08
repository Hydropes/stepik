#include <cstddef>
#include <iostream>
#include <stdexcept>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

struct String
{
    String(const char *str =""){
        this->str = (char*)str;
        size_t i =0;
        while(str[i]!='\0'){
            i++;
        }
        this->size=i;
    };
    String(size_t n, char c){};
    ~String(){};
    String(const String& other){};
    String& operator =(const String& other);
    void append(const String& other);
    size_t size;
    char* str;

    struct MaskString
    {
        MaskString(const char *str ="", size_t from = 0, size_t size = 0){
            this->str = (char*)str;
            this->size=size;
            this->from = from;
        };
        ~MaskString(){
            // delete [] str;
            std::cout<<"was deleted"<<'\n';
        };

        size_t size;
        char* str;
        size_t from;

        String operator[](size_t end )const{
            
            size_t len =  end-this->from;
            // char* new_str = new char[len];                   
            for(size_t i = 0; i<len; i++){
                this->str[i]=*(this->str+i);
            }
            for (size_t i = len; i < this->size; i++)
            {
                this->str[i] = '\0';
            }
            return String(this->str);
            }
    };

    MaskString operator [](size_t start) const {
        char* new_str = new char[this->size];
        for(size_t i = start; i<this->size; i++){
            new_str[i-start]=*(this->str+i);
        }
        return MaskString(new_str, start, this->size);
    }  
    
};

int main(){
    _CrtDumpMemoryLeaks();
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    String const hello("hello");
    String const hell = hello[0][4]; // теперь в hell хранится подстрока "hell"
    String const ell = hello[1][4];  // теперь в ell хранится подстрока "ell"
    std::cout<<hell.str<<'\n';
    std::cout << ell.str << '\n';
}
