#include <iostream>
#include <utility>
using namespace std;

void process_value(int &i)
{
    std::cout << "LValue processed: " << i << std::endl;
}

void process_value(int &&i)
{
    std::cout << "RValue processed: " << i << std::endl;
}

template <typename T>
void my_forward(T&& i)
{
    process_value(forward<T>(i));
}

int main()
{
    int a = 0;
    process_value(a);
    int &&x = 3;
    process_value(x);

    my_forward(x);
}