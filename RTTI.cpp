#include <iostream>

using namespace std;

class A
{
public:
    void print1() {cout<<"print A"<<endl;}
};

class B : public A
{
public:
    void print2() {cout<<"print B"<<endl;}
};

int main()
{
    A a1;
    A *a2 = &a1;
    cout << typeid(a1).name() << endl;
    cout << typeid(a2).name() << endl;

    // B* b1=a2; there is error
    B *b1 = (B *)a2;
    b1->print2();

    B b2;
    A *a3 = &b2;

    return 0;
}