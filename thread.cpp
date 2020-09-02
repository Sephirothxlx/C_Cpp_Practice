#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
using namespace std;


condition_variable cv;
mutex mu;

bool check(){return true;}


void test(){
	unique_lock<mutex> ul(mu);
	cv.wait(ul, [](){return true;});
	cout<<"h"<<endl;
}

int main()
{
	thread t(test);
	t.join();
   cout << "Hello World";
   return 0;
}