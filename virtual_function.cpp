#include <iostream>
using namespace std;

class A
{
public:
    A();
    virtual ~A();
};
A::A()
{
}
A::~A()
{
    cout << "Delete class A" << endl;
}
class B : public A
{
public:
    B();
    ~B();
};
B::B()
{
}
B::~B()
{
    cout << "Delete class B" << endl;
}
int main(int argc, char *argv[])
{
    A *b = new B;
    delete b;
    return 0;
}