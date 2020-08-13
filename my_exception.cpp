#include <iostream>
using namespace std;

class MyException {
    public:
    void what() const;
};

void MyException::what() const {
    cout<<"my exception"<<endl;
}
