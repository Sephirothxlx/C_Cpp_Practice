#include <iostream>

using namespace std;

int add(int a, int b) = delete;

class A
{
public:
    A() = default;
    A(const A &a) = default;
} a;

int main()
{
    cout << typeid(a).name() << endl;
    return 0;
}