#include <memory>
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Test
{
public:
    Test(string s)
    {
        str = s;
        cout << "Test creat\n";
    }
    ~Test()
    {
        cout << "Test delete:" << str << endl;
    }
    string &getStr()
    {
        return str;
    }
    void setStr(string s)
    {
        str = s;
    }
    void print()
    {
        cout << str << endl;
    }

private:
    string str;
};

//it can be returned
unique_ptr<Test> fun()
{
    return unique_ptr<Test>(new Test("789"));
}

// it can be passed as a reference
void foo(unique_ptr<Test> &t)
{
    t->print();
}
// it can be passed as a reference
void fooo(unique_ptr<Test> t)
{
    t->print();
}

int main()
{
    unique_ptr<Test> ptest(new Test("123"));
    unique_ptr<Test> ptest2(new Test("456"));
    ptest->print();
    ptest2 = std::move(ptest); // can't do ptest2=ptest; delete 456
    if (ptest == nullptr)      // can to this kind of check
        cout << "ptest = nullptr\n";
    if (ptest.get() == nullptr)
        cout << "ptest.get() = nullptr\n";
    Test *p = ptest2.release();
    p->print();
    ptest.reset(p);
    ptest->print();
    ptest2 = fun(); //can do it because we used move constructor
    ptest2->print();
    foo(ptest2);
    //fooo(ptest2); can't pass it directly
    fooo(move(ptest2));

    unique_ptr<string> pu1(new string("hello world"));
    unique_ptr<string> pu2;
    // pu2 = pu1; not allowed
    unique_ptr<Test> pu3;
    pu3 = unique_ptr<Test>(new Test("1")); // #2 allowed

    Test* t1 = new Test("111");
    unique_ptr<Test> p1;
    unique_ptr<Test> p2;
    p1.reset(t1);
    // can't reset to the same pointer
    //p2.reset(t1);
    return 0;
}