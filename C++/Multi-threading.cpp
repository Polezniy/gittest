//////////////////////////////
//// File: Multi-threading.cpp
//// Description: An example of multithreading
//// Author: Gleb Demenov
//////////////////////////////

#include <iostream>
#include <thread>

void first_thread() //thread_1
{
	std::cout << "Function: thread_1 \n" << std::endl;
}

void second_thread() //thread_2
{
	std::cout << "Function: thread_2 " << std::endl;
}

int main() // main thread
{
	std::thread t(first_thread); //launching thread_1 in parallel to main thread
	std::thread t2(second_thread); //launching thread_2 in parallel to main thread

	t.join(); // not allowing main thread to be executed before thread_1
	t2.join(); // not allowing main thread to be executed before thread_2

	std::cout << "Main thread" << std::endl;

	system("PAUSE");

	return 0;
}