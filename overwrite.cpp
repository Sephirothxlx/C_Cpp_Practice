#include <iostream>
using namespace std;

class A
{
};

class B : public A
{
};

class Base
{
public:
    Base(int data = 1)
        : b(data)
    {
        cout << "Base()" << endl;
    }
    ~Base()
    {
        cout << "~Base()" << endl;
    }
    virtual B Test()
    {
        cout << "Base::Test()" << endl;
        return B();
    }

    void TestRedefining(){
        cout<<"Base redefine"<<endl;
    }
    int b;
};
class Derive : public Base
{
public:
    Derive(int data = 2)
        : d(data)
    {
        cout << "Derive()" << endl;
    }
    ~Derive()
    {
        cout << "~Derive()" << endl;
    }
    B Test()
    {
        cout << "Derive::Test()" << endl;
        return B();
    }

    void TestRedefining(){
        cout<<"Derive redefine"<<endl;
    }
    int d;
};

int main()
{
    Derive d;
    d.Base::Test();
    d.Test();
    d.TestRedefining();
    return 0;
}