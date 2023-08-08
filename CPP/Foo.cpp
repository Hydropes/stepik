#include <iostream>

 struct Foo {
     void say() const { std::cout << "Foo says: " << msg << "\n"; }
 protected:
     Foo(const char *msg) : msg(msg) { }
 private:
     const char *msg;
 };

 struct F:protected Foo
 {
protected:
    void foo_1(const char *msg){
        Foo(*msg) f;
    }
 };
 

 void foo_says(const Foo &foo) { foo.say(); }
 

int main(){
    Foo foo("aaa");

}

// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));

// ? ? get_foo(const char *msg)
// {
// }