#include <iostream>
#include <cstdint>
using namespace std;

class Base
{
public:
    int i;
    Base() : i(230) {}
    virtual void f()
    {
        cout << "Base::f->" << i << endl;
    }

    virtual void g()
    {
        cout << "Base::g" << endl;
    }

    virtual void h(int j)
    {
        cout << "Base::h->" << i << " " << i + j << endl;
    }
};

class Person
{
public:
    Person() : mId(10), mAge(20) {}
    static int personCount()
    {
        return sCount;
    }

    virtual void print()
    {
        cout << "id: " << mId
             << ", age: " << mAge << endl;
    }
    virtual void job()
    {
        cout << "Person" << endl;
    }
    virtual ~Person()
    {
        cout << "~Person" << endl;
    }

protected:
    static int sCount;
    int mId;
    int mAge;
};

int main()
{
    // wrong way to declare functors
    // since we need to add caller's class as a param
    typedef void (*Fun)(Base *);
    typedef void (*FunWithParam)(Base *, int);
    typedef void (*Func)(Person *);

    Base b;
    b.i = 100;

    cout << "pointer to vtbl(pointer to object b): " << (int **)(&b) << endl; //
    cout << "address of vtbl: " << *(int **)(&b) << endl;
    cout << "address of vtbl: " << hex << "0x" << (*(intptr_t *)&b) << endl;

    cout << "first virtual function address: "
         << "0x" << (*(intptr_t *)*(intptr_t *)&b) << endl;
    cout << "second virtual function address: "
         << "0x" << (*((intptr_t *)*(intptr_t *)(&b) + 1)) << endl;
    cout << dec << endl;

    cout << b.i << endl;
    int **vt = (int **)*(int **)&b;
    Fun pfun = (Fun)(*(intptr_t *)*(intptr_t *)&b); //vitural f();
    printf("f():%p\n", pfun);
    pfun(&b);

    pfun = (Fun)(*((intptr_t *)*(intptr_t *)(&b) + 1)); //vitural g();
    printf("g():%p\n", pfun);
    pfun(&b);

    FunWithParam pfunwithparam = (FunWithParam)(*((intptr_t *)*(intptr_t *)(&b) + 2)); //vitural g();
    printf("h():%p\n", pfunwithparam);
    pfunwithparam(&b, 1);

    Person person;
    int **vtbl = (int **)*(int **)&person;
    Func func1 = (Func)*vtbl; //??

    func1(&person);

    return 0;
}