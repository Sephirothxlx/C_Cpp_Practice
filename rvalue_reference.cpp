// g++ -fno-elide-constructors -std=c++11 copy_move_constructor.cpp

#include <iostream>
#include <utility>
using namespace std;

class B
{
public:
    B() { cout << "B default consturctor" << endl; }
    B(const B &b) { cout << "B copy consturctor" << endl; }
    B(B &&b) { cout << "B move consturctor" << endl; }
    B &operator=(const B &b)
    {
        cout << "B copy assignment operator" << endl;
        return *this;
    }
    B &operator=(B &&b)
    {
        cout << "B move assignment operator" << endl;
        return *this;
    }
    ~B() { cout << "B destructor" << endl; }
};

class A
{
public:
    A() { std::cout << "A default constructor" << std::endl; }
    A(const B& b) : bb(move(b)) { cout << "A user-defined constructor" << endl; }
    A(const A &a)
    {
        std::cout << "A copy constructor" << std::endl;
    }

    A(A &&a)
    {
        cout << "A move constructor" << endl;
    }

    A &operator=(const A &a)
    {
        cout << "A copy assignment operator" << endl;
        return *this;
    }

    A &operator=(A &&a)
    {
        cout << "A move assignment operator" << endl;
        return *this;
    }

    ~A() { cout << "A destructor" << endl; }

    void print() { cout << "I'm A" << endl; }

    B bb;
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

    // test3
    A a3 = move(a2);
    cout << "\n";

    // test4
    A a4((B()));
    cout << "\n";

    B b1;
    A a5(b1);
    cout << "\n";

    const B &b2 = B();
    cout << "\n";

    cout<<boolalpha<<(&b1==&a5.bb)<<endl;

    return 0;
}