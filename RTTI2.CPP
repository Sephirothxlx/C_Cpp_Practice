#include <iostream>
using namespace std;

class A
{
public:
    A() {}
    virtual void foo() { cout << "A foo" << endl; }
    void pp() { cout << "A pp" << endl; }
};

class B : public A
{
public:
    B() {}
    B(int n) : name(n) {}
    int name;
    void foo() { cout << "B foo" << endl; }
    void pp() { cout << "B pp" << endl; }
    void FunctionB() { cout << "Excute FunctionB!" << endl; }
};

int main(int argc, char *argv[])
{
    A a;
    B b;
    A *pa = &a;
    pa->foo();
    pa->pp();

    // not throw bad cast but there is risk
    B &old_reference_to_pointer = (B &)a;

    try
    {
        // throw bad cast
        B &reference_to_pointer1 = dynamic_cast<B &>(a);
    }
    catch (bad_cast e)
    {
        cout<<e.what()<<endl;
    }
    A &reference_to_pointer2 = dynamic_cast<A &>(b);

    // B *pb = dynamic_cast<B*>(pa) will return NULL
    // use dynamic_cast and we can find the risk of converting
    // but with ((B*)pa), we can still use function but the member property is undefined
    if (B *pb = ((B *)pa))
    {
        cout << "Convert from B to A successfully" << endl;
        //function is defined
        ((B *)pa)->FunctionB();
        ((B *)pa)->foo();
        ((B *)pa)->pp();
        (*pa).foo();

        //data is not defined
        cout << (pb->name) << endl;
    }
    else
        cout << "Cannot convert from B to A" << endl;

    return 0;
}
