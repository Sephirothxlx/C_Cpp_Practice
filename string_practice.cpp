#include <string>
#include <iostream>

using namespace std;

int main(int argc, char**args) {
    string s1 = "Hello World!";
    string s2("Hello world!");
    int x = s1.find_first_of("H", 0);
    cout<<x;

    int y = s1.rfind("eH");
    cout<<y;

    s1.insert(2, "xyz", 0, 2);
    cout<<s1;

    s1.erase(2,3);
    cout<<s1<<endl;

    s2.replace(s2.begin()+2, s2.begin()+4, "123", 1);
    cout<<s2<<endl;

    string s3 = s2.substr(2,2);
    cout<<s3<<endl;

    cout<< s1<<endl;
    int tag = s1.compare("Z");
    cout<<(tag<0)<<endl;
    return 0;
}