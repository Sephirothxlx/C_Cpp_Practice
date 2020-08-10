#include <iostream>
#include <string>
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

class B;
class A
{
public:
    shared_ptr<B> pb_;
    ~A()
    {
        cout << "A delete\n";
    }
};

class B
{
public:
    shared_ptr<A> pa_;
    ~B()
    {
        cout << "B delete\n";
    }
};

int main()
{
    shared_ptr<Test> ptest(new Test("123"));
    shared_ptr<Test> ptest2(new Test("456"));
    cout << ptest2->getStr() << endl;
    cout << ptest2.use_count() << endl;
    ptest = ptest2;
    ptest->print();
    cout << ptest.use_count() << endl;  //2
    cout << ptest2.use_count() << endl; //2
    shared_ptr<Test> ptest3 = ptest;
    cout << ptest.use_count() << endl;  //2
    cout << ptest2.use_count() << endl; //2

    unique_ptr<Test> ptest4(new Test("789"));
    // not allowed since ptest3 is a left value
    //shared_ptr<Test> ptest4(ptest3);
    shared_ptr<Test> ptest5(unique_ptr<Test>(new Test("78910")));
    ptest5.get()->print();

    // ptest5 reference +1
    shared_ptr<Test> ptest6(ptest5);
    // ptest5 reference +1
    shared_ptr<Test> ptest7=ptest5;
    ptest6->print();
    ptest7->print();
    cout<<ptest5.use_count()<<endl; //3

    ptest.reset();
    ptest2.reset();
    cout << "-----------------\n";

    shared_ptr<A> pa(new A());
    shared_ptr<B> pb(new B());
    pa->pb_ = pb;
    pb->pa_ = pa;
    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;
    // pa.reset();
    // pb.reset();
    // cout << pa.use_count() << endl;
    // cout << pb.use_count() << endl;
    return 0;
}