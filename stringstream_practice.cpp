#include <sstream>
#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char ** args){
    char cc[100]={0};
    sprintf(cc, "%d %d", 12, 123);
    cout<<cc<<endl;

    const char *s="123 124";
    int f=1;
    int* b=&f,c;
    sscanf(s,"%d %d",b, &c);
    cout<<*b<<endl;

    stringstream ss;
    ss<<"12 a1sdgkjasjdgk sss";
    int s1;
    ss>>s1;
    cout<<s1<<endl;
    string s2;
    ss>>s2;
    cout<<s2<<endl;
    ss<<"124";
    cout<<ss.str()<<endl;

    int*aa=nullptr;

    return 0;
}