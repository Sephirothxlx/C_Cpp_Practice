#include <iostream>
#include <typeinfo>

using namespace std;

template<typename T>
auto getName(const T& t) -> decltype(typeid(t).name()){
    return typeid(t).name();
}


int main(){
    cout<<getName(1)<<endl;
    return 0;
}