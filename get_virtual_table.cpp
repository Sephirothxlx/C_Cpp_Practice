#include <iostream>
#include <cstdint>
using namespace std;

class Base
{
public:
    int i;
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

int main()
{
    // wrong way to declare functors
    // since we need to add caller's class as a param
    typedef void (*Func)(void);
    typedef void (*FuncWithParam)(int);

    typedef void (*Fun)(Base *);
    typedef void (*FunWithParam)(Base *, int);

    Base b;
    b.i = 100;
    Fun pFun = NULL;

    cout << "pointer to vtbl(pointer to object b): " << (int **)(&b) << endl; //
    cout << "pointer to vtbl(pointer to object b): " << (Fun **)(&b) << endl; //
    cout << "address of vtbl: " << *(int **)(&b) << endl;

    // Invoke the first virtual function
    pFun = **((Fun **)(&b));
    pFun(&b); // same as pFun(&b);

    cout << "--------------" << *(Fun **)(&b) << endl;
    Fun *vtable = *((Fun **)(&b));
    vtable[0](&b);
    vtable[1](&b);
    ((FunWithParam)vtable[2])(&b, 50);

    cout << "address of vtbl: " << hex << "0x" << (*(intptr_t *)&b) << endl;
    cout << "first virtual function address: "
         << "0x" << (*(intptr_t *)*(intptr_t *)&b) << endl;
    cout << "second virtual function address: "
         << "0x" << (*((intptr_t *)*(intptr_t *)(&b) + 1)) << endl;
    cout << dec << endl;

    Func pfun = (Func)(*((intptr_t *)*(intptr_t *)(&b))); //vitural f();
    printf("f():%p\n", pfun);
    pfun();

    pfun = (Func)(*((intptr_t *)*(intptr_t *)(&b) + 1)); //vitural g();
    printf("g():%p\n", pfun);
    pfun();

    FunWithParam pfunwithparam = (FunWithParam)(*((intptr_t *)*(intptr_t *)(&b) + 2)); //vitural g();
    printf("h():%p\n", pfunwithparam);
    pfunwithparam(&b, 1);

    return 0;
}