// if this file is included in other files
// we can't define the non member function
void a();

// inline function can be defined at the same time
inline void b(){}

class A{
public:
    // this is initialization list not assignment list!!
    A():d(3), y(3) {

    }
    void func();

    // can define
    const int a=1;

    //can define
    static const int b=1;
    // static variable can't be assigned
    // static int c=2;

    // can't define variable in header file although this is not a header file
    int d;
    const int y;
};

const int h=10;

// can't define variable in header file although this is not a header file
// int t=1;

// can't define member function outside a class declaration in header file although this is not a header file
// void A::func(){}
