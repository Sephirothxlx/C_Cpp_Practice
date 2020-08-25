// extern "C"
// {
// #include "test1.h"
// }
// if test1 is a c file, then we should do the above
#include "test1.h"
#include <iostream>
using namespace std;

int main()
{
    func();
}
