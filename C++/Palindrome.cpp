#include <string>
#include <stdexcept>
#include <iostream>
#include <locale>
#include <algorithm>

class Palindrome
{
public:

	static bool isPalindrome(const std::string& word)
	{
		int check = 0;
		int d = word.size()-1;
		std::locale loc;


		for (int i = 0; i != word.size(); i++)
		{
			if (std::tolower(word[i], loc) == std::tolower(word[d], loc))
			{
				check++;
				d--;
			}
		}

		if (check == word.size())
		{
			return true;
		}

		else if (check != word.size())

		{
			return false;
		}
	}
};

#ifndef RunTests
int main()
{
	std::cout << Palindrome::isPalindrome("Deleveled");
}
#endif