#include "../my_array/my_array.h"
#include "../my_exception.cpp"
#include "other_function.cpp"

// we can declare multiple times
void a();

// but we can only define once
void a(){
}

int main(int argc, char**args){
    a();
    b();
    try{
        throw MyException();
    }catch(MyException &e){
        e.what();
    }
    A a;
    cout<<a.a<<endl;
    cout<<a.d<<endl;
}