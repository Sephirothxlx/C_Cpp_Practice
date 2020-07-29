#include "mystring.h";
#include <iostream>

using namespace std;

int MyString::size(){
	return this->len;
}

MyString::MyString(){
	this->len = 0;
	this->s = new char[1];
	this->s[1]='\0';
}

int main(){
	MyString s("abc");
	cout<<s.size()<<endl;
}