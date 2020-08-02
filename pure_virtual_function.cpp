#include <iostream>
using namespace std;

class A
{
public:
    A(){};
    virtual ~A(){};
    void f1() { cout << "A f1" << endl; };
    virtual void f2() { cout << "A f2" << endl; };
    virtual void f3() = 0;
};
class B : public A
{
public:
    B(){};
    virtual ~B(){};
    void f1() { cout << "B f1" << endl; };
    virtual void f2() { cout << "B f2" << endl; };

    // if we want to "new B", we have to implement this function
    virtual void f3() { cout << "B f3" << endl; };
};
int main(int argc, char *argv[])
{
    A *m_j = new B;
    m_j->f1();
    m_j->f2();
    m_j->f3();
    delete m_j;
    return 0;
}