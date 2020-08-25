#include <iostream>

using namespace std;

template <typename T1, typename T2>
class A{
public:
    void work(T1, T2);
};

template <typename T1, typename T2>
void A<T1, T2>::work(T1 t1, T2 t2){}

int main(int argc, char**args){
    return 0;
}