#include <iostream>

using namespace std;

int main()
{
    // 1d
    char *a = new char[20];

    // 2d
    char **b = new char *[10];
    for (int i = 0; i < 10; i++)
    {
        b[i] = new char[2];
    }

    delete[] a;
    delete[] b;
    return 0;
}