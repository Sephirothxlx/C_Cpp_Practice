#include <iostream>
using namespace std;

class B
{
    virtual void f(){};
};
class D : public B
{
    virtual void f(){};
};

int main()
{
    //static_cast
    short a = 100;
    short *pa = &a;
    int b = static_cast<int>(a);
    // invalid: int*pb=static_cast<int*>(pa);

    //dynamic_cast
    int c = 1000;
    // invalid: short* c = dynamic_cast<short*>(&c);

    B *pb = new D; // unclear but ok
    B *pb2 = new B;
    D *pd = dynamic_cast<D *>(pb);   // ok: pb actually points to a D
    D *pd2 = dynamic_cast<D *>(pb2); // pb2 points to a B not a D, now pd2 is NULL
    return 0;
}