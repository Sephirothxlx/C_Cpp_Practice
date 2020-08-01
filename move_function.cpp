#include <iostream>
#include <utility>
#include <string>

using namespace std;

class A{
public:
    A(){}
    A(string s):s(s){}
    string s;
};

/**
 * move function will give up ownership!!
*/

int main(){
    // test1 string after move
    string s1("sdjg");
    string s2(move(s1));
    cout<<s1<<endl;

    //test2 class after move
    A a1("sdg");
    A a2(move(a1));
    cout<<a1.s<<endl;
    cout<<a2.s<<endl;

    return 0;
}