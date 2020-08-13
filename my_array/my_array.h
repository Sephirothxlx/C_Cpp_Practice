#ifndef MY_ARRAY
#define MY_ARRAY

class MyArray
{
public:
    MyArray();
    ~MyArray();
    MyArray(int i);
    MyArray(const MyArray& x);
    MyArray& operator=(const MyArray& x);
    MyArray(MyArray&& x);
    MyArray& operator=(MyArray&& x);

    int& operator[](int i) const;

    int length() const;
private:
    int size;
    const int expandSize=50;
};

#endif