//////////////////////////////
/// File: Source.cpp
/// Description: This program represents the basics of the game called "Hangman". 
/// Author: Gleb Demenov
//////////////////////////////

#include <iostream>//Library includes standard input/output stream objects.
#include <time.h>//Library allows to manipulate date and time information.


void UserInterface();//Easy user interface.
void HardUserInterface();//Hard and normal user interface.
void InputInterface();//Input interface.
void HideFunc(char _buf[], int _l);//Function that replaces all letters with '-' symbol.
void Guess(char _input, int _len);//Checking function.
void Mistakes();//Function that builds hangman.
void GuessedLetters(char _input);//Incorrect letter function.

char g_letter;//Input.
int g_attempts;//Attempts.
int g_check = 0;//Checking if the word is complete.

char g_h1, g_h2, g_h3, g_h4, g_h5, g_h6;//Hangman parts.

char g_leftleg;//Left leg.
char g_rightleg;//Right leg.
char g_leftarm;//Left arm.
char g_rightarm;//Right arm.

char ActualWord[10] = { 0 };//Empty array.
char HiddenArray[10] = { 0 };//An array with a hidden word.
char Incorrect[10] = {};//Incorrect Letters.

int g_len;//Length
bool g_correct;//The value defines if letter is correct(true) or not(false).


int main()
{
	char EasyWordList[5][6] = { "mango", "chips", "fries", "drink", "sauce" };//A list of words for easy level.
	char NormalWordList[5][7] = { "animal", "castle", "dinner", "window", "ticket" };//A list of words for normal level.
	char HardWordList[5][11] = { "basketball", "technology", "goverment" , "depression", "watermelon"};//A list of words for hard level.
	char* d_array[4] = { "Easy", "Normal", "Hard", "Normal" };//A list of difficulties.

	srand(time(NULL));//Seed.

	int m_ii = rand() % 5;//Randomize a row and column of array.

 
	int m_decision = 0;
	int m_menu = 0;
	int m_difficulty;

	g_leftarm = ' ';
	g_rightarm = ' ';

	g_rightleg = ' ';
	g_leftleg = ' ';

	g_h1 = ' ';//H
	g_h2 = ' ';//A
	g_h3 = ' ';//N
	g_h4 = ' ';//G
	g_h5 = ' ';//M
	g_h6 = ' ';//A
			   //N

	while (m_menu < 5)
	{
		system("cls");
		std::cout << "  Press 1 to Start\n";
		std::cout << "  Press 2 for Options\n";
		std::cout << "  Press 3 to Exit\n";
		std::cin >> m_decision;

		if (m_decision == 3)
		{
			system("cls");
			return(0);
		}

		if (m_decision == 2)
		{
			system("cls");

			std::cout << "Press 1 to set difficulty to Easy\n";
			std::cout << "Press 2 to set difficulty to Normal\n";
			std::cout << "Press 3 to set difficulty to Hard\n\n";

			std::cout << "Current difficulty: " << d_array[3] << "\n\n";

			std::cin >> m_difficulty;

			if (m_difficulty == 1)
			{
				d_array[3] = d_array[0];//EASY
			}
			if (m_difficulty == 2)
			{
				d_array[3] = d_array[1];//NORMAL
			}
			if (m_difficulty == 3)
			{
				d_array[3] = d_array[2];//HARD
			}
			system("cls");

			std::cout << "Difficulty set to: " << d_array[3] << "\n\n";

			system("pause");
		}

		if (m_decision == 1)
		{
			m_menu = 5;
			system("cls");
		  }			
	}

	if (d_array[3] == d_array[1])//if difficulty normal 
	{
		g_attempts = 6;
		strcpy(ActualWord, NormalWordList[m_ii]);
		strcpy(HiddenArray, ActualWord);

		g_len = strlen(ActualWord);
		HideFunc(HiddenArray, g_len);

		while (g_check < g_len)
		{
			if (g_attempts == 0)
			{
				break;
			}

			HardUserInterface();//HARD USER-
			InputInterface();//-INTERFACE
			Guess(g_letter, g_len);

			if (g_correct == false)
			{
				GuessedLetters(g_letter);
				Mistakes();

			}
		}
	}

	if (d_array[3] == d_array[2])//if difficulty hard
	{
		g_attempts = 6;
		strcpy(ActualWord, HardWordList[m_ii]);
		strcpy(HiddenArray, ActualWord);

		g_len = strlen(ActualWord);
		HideFunc(HiddenArray, g_len);

		while (g_check < g_len)
		{
			if (g_attempts == 0)
			{
				break;
			}

			HardUserInterface();//HARD USER-
			InputInterface();//-INTERFACE
			Guess(g_letter, g_len);

			if (g_correct == false)
			{
				g_attempts--;
				Mistakes();
				GuessedLetters(g_letter);
			}
		}
	}
	if (d_array[3] == d_array[0]) //if difficulty easy
	{
		g_attempts = 10;
		strcpy(ActualWord, HardWordList[m_ii]);
		strcpy(HiddenArray, ActualWord);

		g_len = strlen(ActualWord);
		HideFunc(HiddenArray, g_len);

		while (g_check < g_len)
		{
			if (g_attempts == 0)
			{
				break;
			}

			UserInterface();//USER-
			InputInterface();//-INTERFACE
			Guess(g_letter, g_len);

			if (g_correct == false)
			{
				g_attempts--;
				Mistakes();
				GuessedLetters(g_letter);
			}
		}
	}

	////ENDING SCREEN
	if (g_check == g_len)
	{
		system("cls");

		////////////////////// USER INTERFACE /////////////////
		std::cout << "                 -----------------\n";
		std::cout << "                 H A N G   M A N\n";
		std::cout << "                 -----------------\n\n\n\n";

		std::cout << "      " << g_h3 << g_h3 << g_h3 << g_h3 << g_h3 << "\n";
		std::cout << "      " << g_h2 << "   " << g_h4 << "\n";
		std::cout << "      " << g_h2 << "   " << g_h5 << "\n";
		std::cout << "      " << g_h2 << "  " << (char)g_leftarm << g_h6 << (char)g_rightarm << "\n";
		std::cout << "      " << g_h2 << "  " << "" << (char)g_leftleg << (char)g_rightleg << "\n";
		std::cout << "      " << g_h2;
		std::cout << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << "                   " << "Guessed letters: " << "\n";
		std::cout << "                                 ";

		for (int i = 0; i < 10; i++)
		{
			std::cout << Incorrect[i] << " ";
		}

		std::cout << "\n\n\n";

		std::cout << "      " << HiddenArray << "                    " << " Guesses: " << g_attempts << "\n\n\n\n";

		std::cout << "YOU WIN\n\n\n";
		std::cout << "Congratulations!\n\n";
		system("PAUSE");
		return 0;
	}

	if (g_attempts == 0)
	{
		system("cls");

		////////////////////// USER INTERFACE /////////////////
		std::cout << "                 -----------------\n";
		std::cout << "                 H A N G   M A N\n";
		std::cout << "                 -----------------\n\n\n\n";

		std::cout << "      " << g_h3 << g_h3 << g_h3 << g_h3 << g_h3 << "\n";
		std::cout << "      " << g_h2 << "   " << g_h4 << "\n";
		std::cout << "      " << g_h2 << "   " << g_h5 << "\n";
		std::cout << "      " << g_h2 << "  " << (char)g_leftarm << g_h6 << (char)g_rightarm << "\n";
		std::cout << "      " << g_h2 << "  " << (char)g_leftleg << (char)g_rightleg << "\n";
		std::cout << "      " << g_h2;
		std::cout << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << "                   " << "Guessed letters: " << "\n";
		std::cout << "                                 ";

		for (int i = 0; i < 10; i++)
		{
			std::cout << Incorrect[i] << " ";
		}

		std::cout << "\n\n\n";

		std::cout << "      " << HiddenArray << "                    " << " Guesses: " << g_attempts << "\n\n\n\n";

		std::cout << "Word > " << ActualWord << "\n\n";

		std::cout << "YOU LOST\n\n";
		std::cout << "GAME OVER\n\n";
		system("PAUSE");
		return 0;
	}
}

void UserInterface()
{
	system("cls");

	////////////////////// USER INTERFACE /////////////////
	std::cout << "                 -----------------\n";
	std::cout << "                 H A N G   M A N\n";
	std::cout << "                 -----------------\n\n\n\n";

	std::cout << "      " << g_h3 << g_h3 << g_h3 << g_h3 << g_h3 << "\n";
	std::cout << "      " << g_h2 << "   " << g_h4 << "\n";
	std::cout << "      " << g_h2 << "   " << g_h5 << "\n";
	std::cout << "      " << g_h2 << "  " << (char)g_leftarm << g_h6 << (char)g_rightarm << "\n";
	std::cout << "      " << g_h2 << "  " << "" << (char)g_leftleg << (char)g_rightleg << "\n";
	std::cout << "      " << g_h2;
	std::cout << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << "                   " << "Guessed letters: " << "\n";
	std::cout << "                                 ";

	for (int i = 0; i < 10; i++)
	{
		std::cout << Incorrect[i] << " ";
	}

	std::cout << "\n\n\n";

	std::cout << "      " << HiddenArray << "                    " << " Guesses: " << g_attempts << "\n\n\n\n";

}
void InputInterface()
{
		std::cout << "    " << "Enter a letter: ";
		std::cin >> g_letter;
}
void HardUserInterface()
{
	g_h1 = '_';
	g_h2 = '|';
	g_h3 = '_';
	g_h4 = '|';

	system("cls");

	////////////////////// USER INTERFACE /////////////////
	std::cout << "                 -----------------\n";
	std::cout << "                 H A N G   M A N\n";
	std::cout << "                 -----------------\n\n\n\n";

	std::cout << "      " << g_h3 << g_h3 << g_h3 << g_h3 << g_h3 << "\n";
	std::cout << "      " << g_h2 << "   " << g_h4 << "\n";
	std::cout << "      " << g_h2 << "   " << g_h5 << "\n";
	std::cout << "      " << g_h2 << "  " << (char)g_leftarm << g_h6 << (char)g_rightarm << "\n";
	std::cout << "      " << g_h2 << "  " << "" << (char)g_leftleg << (char)g_rightleg << "\n";
	std::cout << "      " << g_h2;
	std::cout << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << g_h1 << "                   " << "Guessed letters: " << "\n\n";
	std::cout << "                                 ";
	
	for (int i = 0; i < 10; i++)
	{
		std::cout << Incorrect[i] << " ";
	}
	
	std::cout << "\n\n\n";

	std::cout << "      " << HiddenArray << "                    " << " Guesses: " << g_attempts << "\n\n\n\n";

	//////////////// END OF USER INTERFACE ///////////////

}
void HideFunc(char _buf[], int _l)
{

	for (int i = 0; i < _l; i++)
	{
		_buf[i] = '-';
	}
}
void Guess(char _input, int _len)//CHECKING LETTER
{
	g_correct = false;

	for (int i = 0; i < _len; i++)
	{
		if (!(((_input >= '0') && (_input <= '100')) && ((_input >= 'A') && (_input <= 'z'))))//IF ANY OTHER SYMBOL ENTERED
		{
			g_correct = true;
			break;
		}
		if (_input == ActualWord[i])
		{
			if (HiddenArray[i] != _input)
			{
				HiddenArray[i] = _input;
				g_check++;
				g_correct = true;
			}

			else//IF LETTER IS REPEATED
			{
				g_correct = true;
				break;
			}
		}
	}
}
void Mistakes()
{
  //// 1 MISTAKE
  if (g_attempts == 9)
  {
	  g_h1 = '_';
  }

  ////2 MISTAKE
  if (g_attempts == 8)
  {
	  g_h2 = '|';
  }

  ////3 MISTAKE
  if (g_attempts == 7)
  {
	  g_h3 = '_';
  }

  ////4 MISTAKE
  if (g_attempts == 6)
  {
	  g_h4 = '|';
  }

  ////5 MISTAKE
  if (g_attempts == 5)
  {
	  g_h5 = '0';
  }

  ////6 MISTAKE
  if (g_attempts == 4)
  {
	  g_h6 = '|';
  }

  ////7 MISTAKE
  if (g_attempts == 3)
  {
	  g_leftleg = 47;
  }

  ////8 MISTAKE
  if (g_attempts == 2)
  {
	  g_rightleg = 92;
  }

  ////9 MISTAKE
  if (g_attempts == 1)
  {
	  g_leftarm = 47;
  }

   ////10 MISTAKE
  if (g_attempts == 0)
  {
	  g_rightarm = 92;
  }

}
void GuessedLetters(char _input)
{
	for (int i = 0; i < 20; i++)
	{
		if (_input == Incorrect[i])//IF WRONG LETTER REPEATED
		{
			break;
		}

		if (Incorrect[i] != 0)//IF SLOT FOR LETTER IS OCCUPIED
		{
			i++;
		}
		else//WRONG LETTER WILL BE IN FREE SLOT
		{
			Incorrect[i] = _input;
			g_attempts--;
			break;
		}
	}
}