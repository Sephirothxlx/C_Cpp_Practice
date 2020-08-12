#include <memory>
#include <iostream>
using namespace std;

class B;

class A
{
public:
    int a;
    weak_ptr<B> _pb;
    A() : a(3) { cout << "A default constructor" << endl; };
    ~A() { cout << "A deconstructor" << endl; }
};

class B
{
public:
    weak_ptr<A> _pa;
    B() { cout << "B default constructor" << endl; }
    ~B() { cout << "B deconstructor" << endl; }
};

int main()
{
    shared_ptr<int> share_p1(new int(5));
    weak_ptr<int> weak_p1 = share_p1;
    cout << share_p1.use_count() << endl;
    cout << weak_p1.use_count() << endl;
    //weak_p1.lock(); reference + 1
    shared_ptr<int> share_p2 = weak_p1.lock();
    cout << share_p1.use_count() << endl;
    cout << weak_p1.use_count() << endl;
    share_p1.reset();
    if (weak_p1.expired())
    {
        cout << "shared_ptr object has been destory" << endl;
    }
    cout << share_p2.use_count() << endl;
    cout << weak_p1.use_count() << endl;
    shared_ptr<int> share_p3 = weak_p1.lock();
    cout << *share_p3.get() << endl;

    shared_ptr<A> share_p4(new A());
    weak_ptr<A> weak_p2 = share_p4;
    share_p4.reset();
    cout << boolalpha << weak_p2.expired() << endl;

    // a solution: reference to each other
    shared_ptr<A> pa(new A);
    shared_ptr<B> pb(new B);
    pa->_pb = pb;
    pb->_pa = pa;
    cout << pa.use_count() << endl;
    cout << pb.use_count() << endl;
}