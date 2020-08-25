#include <iostream>

using namespace std;

class A{
    public:
    A():a(1){}
    int a;
    friend ostream& operator << (ostream&out, A& a);
};

ostream& operator << (ostream&out, A& a) {
    out<<a.a<<"hahah\n";
    return out;
}

int main(int argc, char**args){
    A a;
    cout<<a<<endl;
    return 0;
}
