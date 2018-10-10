//////////////////////////////
//// File: Palindrome.cpp
//// Description: This program checks if the input word is palindrome
//// Author: Gleb Demenov
//////////////////////////////

#include <string>
#include <stdexcept>
#include <iostream>
#include <locale>
#include <algorithm>

class Palindrome
{
public:

	static bool isPalindrome(const std::string& word) //function that checks for palindrome
	{
		int check = 0; //flag
		int d = word.size()-1; 
		std::locale loc; // for std::lowercase


		for (int i = 0; i != word.size(); i++) 
		{
			if (std::tolower(word[i], loc) == std::tolower(word[d], loc))  //checks all letters
			{
				check++; 
				d--;
			}
		}

		if (check == word.size()) //if all the letters pass the check - return true
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