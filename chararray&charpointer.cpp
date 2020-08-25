#include <iostream>
using namespace std;

int main(int argc, char **args)
{
    char a[] = "abcd";
    // char * b = "123"; is not allowed in c++11
    char *b = a;
    // char c[]; is not allowed
    cout << a << endl;
    cout << b << endl;
}