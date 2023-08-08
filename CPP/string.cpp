#include <iostream>
#include <cstddef> //size_t
#include <cstring>// strlen, strcpy
using namespace std;

struct String
{
    String(const char *str=""){
        size = strlen(str);
        this->str = new char [size+1];
        for(size_t i= 0; i<=size; ++i){
            this->str[i]=str[i];
        }
    }
    String(size_t n, char c){
        size = n;
        this->str = new char [size+1];
        for(size_t i= 0; i<size; ++i){
            this->str[i]=c;
        }
        //cout<<this->str<<'\n';
    }
    String(const String & other){
        size = other.size;
        this->str = new char[size + 1];
        for (size_t i = 0; i <= size; ++i)
        {
            this->str[i] = other.str[i];
        }
        this->str[size] = '\0';
    }
    String &operator=(const String &other){
        if (this!=& other){
            delete [] this->str;
            size = other.size;
            this->str = new char[size + 1];
            for (size_t i = 0; i <= size; ++i)
            {
                this->str[i] = other.str[i];
            }
            this->str[size] = '\0';
        }
        return *this;
    }
    ~String(){
        delete [] this->str;
    }
    size_t get_len(){
        return this->size;
    }

    void append(String &other){
        size_t total_size =size+other.size;
        char * new_str = new char[total_size+1];
        strncpy(new_str, str, size);
        strncat(new_str+size, other.str, other.size);
        new_str[total_size]='\0';
        delete [] str;
        str = new_str;
        size = strlen(str);
        // size_t other_size = other.get_len();
        // size_t total_size = size+other_size;
        // cout<<total_size<<'\n';
        // char * tmp = new char [total_size+1];
        // copy(str, str+size, tmp);
        // delete [] str;
        // str = tmp;
        // for (size_t i=size; i<total_size; ++i){
        //     str[i] = other.str[i-size];
        // }
        // str[total_size]='\0';
        // delete [] other.str;
    }
    size_t size;
    char *str;
};


int main()
{
    // String str1("aaaa bdbdbdas sb");
    String str1(5, 'a');
    String str2("bbb");
    str1.append(str2);
    cout<<str1.str<<"\n";
    String str3(str1);
    String str4;
    str4 = str1;
    cout << str4.str << "\n";
    return 0;
}