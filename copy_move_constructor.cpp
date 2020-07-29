// g++ -fno-elide-constructors -std=c++11 copy_move_constructor.cpp

#include <iostream>
#include <utility>
using namespace std;

class A
{
public:
    A() { std::cout << "default constructor" << std::endl; }
    A(const A &a)
    {
        std::cout << "copy constructor" << std::endl;
    }

    A(A &&a)
    {
        cout << "move constructor" << endl;
    }

    A &operator=(const A &a)
    {
        cout << "copy assignment operator" << endl;
        return *this;
    }

    A &operator=(A &&a)
    {
        cout << "move assignment operator" << endl;
        return *this;
    }

    ~A() { cout << "destructor" << endl; }

    void print() { cout << "I'm A" << endl; }
};

// named return value
A getNA()
{
    A a;
    return a;
}

// return value
A getA()
{
    return A();
}

int main()
{
    // test1: named return value
    A a1(getNA());
    cout << "\n";

    // test2: return value
    A a2(getA());
    cout << "\n";

    //test3
    A a3 = move(a2);
    cout << "\n";

    return 0;
}