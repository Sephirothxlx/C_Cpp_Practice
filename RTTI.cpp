#include <iostream>
#include <typeinfo>

using namespace std;

class A
{
public:
    void print1() { cout << "print A" << endl; }
};

class B : public A
{
public:
    void print2() { cout << "print B" << endl; }
};

void printTypeInfo(const A *px)
{
    cout << "typeid(px) -> " << typeid(px).name() << endl;
    cout << "typeid(*px) -> " << typeid(*px).name() << endl;
}


struct calc_data_1 {

};

struct calc_data_2 {

};

int main()
{
    A a1;
    A *a2 = &a1;
    cout << typeid(a1).name() << endl;
    cout << typeid(a2).name() << endl;

    // B* b1=a2; there is error
    B *b1 = (B *)a2;
    b1->print2();

    B b2;
    A *a3 = &b2;

    printTypeInfo(&a1);
    printTypeInfo(&b2);

    struct calc_data_1 data1;
    struct calc_data_2 data2;
    struct calc_data_1 data3;

    cout<<boolalpha<<(typeid(data1)==typeid(data2))<<endl;
    cout<<boolalpha<<(typeid(data1)==typeid(data3))<<endl;

    return 0;
}