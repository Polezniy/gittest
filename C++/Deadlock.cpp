//////////////////////////////
//// File: Deadlock.cpp
//// Description: Simulating Deadlock condition
//// Author: Gleb Demenov
//////////////////////////////

#include <iostream>
#include <thread>
#include <mutex> // Mutual exclusion

std::mutex mtx; // Mutex for critical section
std::mutex mtx2;

void printing(int n) // Critical section_1
{
	mtx.lock(); //mutex1 locked

	float *banana = new float[99999];  //Delay between locks

	for (unsigned int i = 0; i < 99999; ++i)
	{
		banana[i] = 100.0f * i;

	}

	std::cout << "Thread1 about to lock mutex2" << std::endl;
	mtx2.lock(); //can't lock, mutex2 already locked
	std::cout << "Printing thread number:" << n << std::endl;

	mtx2.unlock();
	mtx.unlock();
}

void printing2(int n) // Critical section_2
{
	mtx2.lock(); //mutex2 locked

	std::cout << "Thread2 about to lock mutex1" << std::endl;
	mtx.lock(); //can't lock, mutex1 already locked

	std::cout << "Printing thread number:" << n << std::endl;

	mtx.unlock();
	mtx2.unlock();
}
int main() //main thread
{
	std::thread t(printing, 1); //launching thread_1 in parallel to main thread
	std::thread t2(printing2, 2); //launching thread_2 in parallel to main thread

	t.join(); // not allowing main thread to be executed before thread_1
	t2.join(); // not allowing main thread to be executed before thread_2

	std::cout << "Main thread" << std::endl;

	system("PAUSE");

	return 0;
}
