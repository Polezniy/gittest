//////////////////////////////
//// File: Race_condition.cpp
//// Description: Simulating race condition
//// Author: Gleb Demenov
//////////////////////////////

#include <iostream>
#include <thread>

void printing(int n) // Critical section
{
	std::cout << "Printing thread number:" << n << std::endl; //shared data
}

int main() //main thread
{
	std::thread t(printing,1); //launching thread_1 in parallel to main thread
	std::thread t2(printing,2); //launching thread_2 in parallel to main thread

	t.join(); // not allowing main thread to be executed before thread_1
	t2.join(); // not allowing main thread to be executed before thread_2

	std::cout << "Main thread" << std::endl;

	system("PAUSE");

	return 0;
}
/**/