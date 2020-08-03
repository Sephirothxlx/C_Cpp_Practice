#include <iostream>

using namespace std;
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
    static void output()
    {
        cout << m_nPointCount << endl;
    }

private:
    int i=0;
    static int m_nPointCount;
};

// need this line
int Point::m_nPointCount=0;

int main()
{
    Point pt;
    pt.output();
    return 0;
}