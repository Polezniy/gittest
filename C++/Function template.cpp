#include <iostream>

using namespace std;

template <class T>

T maxOutOfTwo(T t, T n)
{
	if (t > n)
	{
		return t;
	}
	else
	{
		return n;
	}
}


int main()
{
	int num1;
	int num2;
	int result;

	cout << "Welcome, please enter to numbers and the program ";
	cout << "will return which is max.\n\n";

	cout << "Number 1 - >";
	cin >> num1;

	cout << "\nNumber 2 - >";
	cin >> num2;

	result = maxOutOfTwo(num1, num2);

	cout << "\n" << result << " is bigger." << endl;
	system("PAUSE");

	return 0;
}

