#include <iostream>
#include "test1.h"
#include "test2.cpp"
using namespace std;

int a=1;
void func();
int main(int argc, char** args){
    func();
    cout<<a<<endl;
}