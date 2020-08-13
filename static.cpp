#include <iostream>

using namespace std;

class A
{
public:
    A() : i(1) {}
    int i;
};

class Point
{
public:
    Point()
    {
        m_nPointCount++;
    }
    ~Point()
    {
        m_nPointCount--;
    }

    // non static function can access static variable
    void print()
    {
        cout << j << endl;
    }

    // static function can't access non static variable
    static void output()
    {
        cout << a.i << endl;
        cout << m_nPointCount << endl;
        cout << j << endl;
    }

private:
    int i = 0;
    static int m_nPointCount;
    static const int j = 3;
    static A a;
};

// need this line to define m_nPointCount
int Point::m_nPointCount = 1;
// need this line to define a
A Point::a;

int main()
{
    Point pt;
    pt.output();
    return 0;
}