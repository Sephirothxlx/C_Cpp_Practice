#include <iostream>
using namespace std;

class CBase
{
public:
    virtual void FunTest1(int _iTest)
    {
        cout << "CBase: : FunTest1() " << endl;
    }
    void FunTest2(int _iTest)
    {
        cout << "CBase: : FunTest2() " << endl;
    }
    virtual void FunTest3(int _iTest1)
    {
        cout << "CBase: : FunTest3() " << endl;
    }
    virtual void FunTest4(int _iTest)
    {
        cout << "CBase: : FunTest4() " << endl;
    }
};
class CDerived : public CBase
{
public:
    virtual void FunTest1(int _iTest)
    {
        cout << "CDerived: : FunTest1() " << endl;
    }
    virtual void FunTest2(int _iTest)
    {
        cout << "CDerived: : FunTest2() " << endl;
    }
    void FunTest3(int _iTest1)
    {
        cout << "CDerived: : FunTest3() " << endl;
    }
    virtual void FunTest4(int _iTest1, int _iTest2)
    {
        cout << "CDerived: : FunTest4() " << endl;
    }
};
int main()
{
    CBase *pBase = new CDerived;
    pBase->FunTest1(0);
    pBase->FunTest2(0);
    pBase->FunTest3(0);
    pBase->FunTest4(0);

    // CBase doesn't have void FunTest4(int _iTest1, int _iTest2)
    // hence we need to explicitly downcast this pointer.
    // use dynamic_cast is better
    ((CDerived*)pBase)->FunTest4(0,0);
    delete pBase;
    return 0;
}