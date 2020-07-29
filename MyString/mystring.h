#ifndef MYSTRING_H
#define MYSTRING_H

class MyString {
public:
	int len;
	MyString();
	MyString(const char * p);
	MyString(const MyString& p);
	MyString& operator=(const MyString& p);
	MyString(MyString&& p);
	MyString& operator=(MyString&& p);
	~MyString();
	int size();
	char operator[](int pos);
	MyString operator+(MyString p);
private:
	char * s;
};

#endif
