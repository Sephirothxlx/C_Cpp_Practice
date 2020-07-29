#include <iostream>
#include <utility>
using namespace std;

template <typename T, typename... Args>
T *createInstance(Args &&... args)
{
    return new T(std::forward<Args>(args)...);
}

class A
{
public:
    A() {}
    A(int &a, int &b) : a(a), b(b) { cout << "constructor 1" << endl; }
    A(int &&a, int &&b) : a(a), b(b) { cout << "constructor 2" << endl; }
    int getA() { return a; }
    int getB() { return b; }

private:
    int a;
    int b;
};

void processValue(int &a) { cout << "lvalue" << endl; }
void processValue(int &&a) { cout << "rvalue" << endl; }

template <typename T>
void forwardValue(T &&val)
{
    processValue(std::forward<T>(val));
}
void test_forward()
{
    int i = 0;
    forwardValue(i);
    forwardValue(0);
}

int main()
{
    auto i = createInstance<A, int, int>(1, 2);
    cout << i->getA() << " " << i->getB() << endl;
    auto a = 3;
    auto b = 4;

    // notice that we need to use int& for reference collapsing
    auto j = createInstance<A, int &, int &>(a, b);
    cout << j->getA() << " " << j->getB() << endl;

    // test perfect forwarding
    test_forward();
    return 0;
}