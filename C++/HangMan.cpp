 /// @Source.cpp
/// @ This programm represents the basics of the game called "Hangman". 


#include <iostream>//Library includes standard input/output stream objects.
#include <time.h>

////FUNCTIONS////
void UserInterface();//USER INTERFACE
void HardUserInterface();//HARD AND NORMAL INTERFACE
void InputInterface();//INPUT INTERFACE
void StarFun(char buf[], int l);
void Guess(char input, int len);
void Mistakes();
void GuessedLetters(char input);

////GLOBAL VARIABLES////
char g_Letter;//INPUT
int g_Attempts;//ATTEMPTS
int g_Check = 0;//CHECKING IF THE WORD COMPLETE

char R1, R2, R3, R4, R5, R6;//HANGMAN PARTS

char g_leftleg;//LEFT LEG
char g_rightleg;//RIGHT LEG
char g_leftarm;//LEFT ARM
char g_rightarm;//RIGHT ARM

int len;
int Choice;
bool Correct;

////GLOBAL ARRAYS////
char HiddenWord[10] = {};//Empty array
char StarsArray[10] = { 0 };//Stars array
char Incorrect[10] = { 0 };//Incorrect Letters

int main()
{
	char EasyWordList[5][6] = { "mango", "chips", "fries", "drink", "sauce" };
	char NormalWordList[5][7] = { "animal", "castle", "dinner", "window", "ticket" };
	char HardWordList[5][11] = { "basketball", "technology", "goverment" , "depression", "watermelon"};
	char* d_array[4] = { "Easy", "Normal", "Hard", "Normal" };//a list of difficulties

	srand(time(NULL));//seed

	int ii = rand() % 5;

 
	int Decision = 0;
	int Difficulty;
	g_leftarm = ' ';
	g_rightarm = ' ';

	g_rightleg = ' ';
	g_leftleg = ' ';

	R1 = ' ';//H
	R2 = ' ';//A
	R3 = ' ';//N
	R4 = ' ';//G
	R5 = ' ';//M
	R6 = ' ';//A
			 //N

	while (Decision < 5)
	{
		system("cls");
		std::cout << "  Press 1 for Singleplayer\n";
		std::cout << "  Press 2 for Multiuplayer\n";
		std::cout << "  Press 3 for Options\n";
		std::cout << "  Press 4 to Exit\n";
		std::cin >> Decision;

		if (Decision == 4)
		{
			system("cls");
			return(0);
		}

		if (Decision == 3)
		{
			system("cls");

			std::cout << "Press 1 to set difficulty to Easy\n";
			std::cout << "Press 2 to set difficulty to Normal\n";
			std::cout << "Press 3 to set difficulty to Hard\n\n";

			std::cout << "Current difficulty: " << d_array[3] << "\n\n";

			std::cin >> Difficulty;

			if (Difficulty == 1)
			{
				d_array[3] = d_array[0];//EASY
			}
			if (Difficulty == 2)
			{
				d_array[3] = d_array[1];//NORMAL
			}
			if (Difficulty == 3)
			{
				d_array[3] = d_array[2];//HARD
			}
			system("cls");

			std::cout << "Difficulty set to: " << d_array[3] << "\n\n";

			system("pause");
		}
		if (Decision == 2)
		{
			Decision = 5;//TO FINISH THE MENU LOOP
			system("cls");

			std::cout << "Welcome to multiplayer!\n\n";
			std::cout << "Player 1\n";
			std::cout << "Enter the word (10 letters max) > ";
			std::cin >> HiddenWord;

			len = strlen(HiddenWord);
			strcpy(StarsArray, HiddenWord);
			StarFun(StarsArray, len);

			system("cls");

			std::cout << StarsArray << "\n\n";
			std::cout << "Press 1 to Continue\n\n";
			std::cout << "Press 2 to Show the word\n\n";
			std::cin >> Choice;

			switch (Choice)
			{

			case (1): 

				g_Attempts = 6;

				while (g_Check < len)
				{
					if (g_Attempts == 0)
					{
						break;
					}

					HardUserInterface();//HARD USER-
					InputInterface();//-INTERFACE
					Guess(g_Letter, len);

					if (Correct == false)
					{
						GuessedLetters(g_Letter);
						Mistakes();

					}
				}
			}

		}
		if (Decision == 1)
		{
			Decision = 5;//TO FINISH MENU LOOP
			system("cls");

			if (d_array[3] == d_array[1])//if difficulty normal 
			{		
				g_Attempts = 6;
				strcpy(HiddenWord, NormalWordList[ii]);
				strcpy(StarsArray, HiddenWord);

				len = strlen(HiddenWord);
				StarFun(StarsArray, len);

				while (g_Check < len)
				{
					if (g_Attempts == 0)
					{
						break;
					}

					HardUserInterface();//HARD USER-
					InputInterface();//-INTERFACE
					Guess(g_Letter, len);

					if (Correct == false)
					{
						GuessedLetters(g_Letter);
						Mistakes();
						
					}
				}
			}

			if (d_array[3] == d_array[2])//if difficulty hard
			{
				g_Attempts = 6;
				strcpy(HiddenWord, HardWordList[ii]);
				strcpy(StarsArray, HiddenWord);

				len = strlen(HiddenWord);
				StarFun(StarsArray, len);

				while (g_Check < len)
				{
					if (g_Attempts == 0)
					{
						break;
					}

					HardUserInterface();//HARD USER-
					InputInterface();//-INTERFACE
					Guess(g_Letter, len);

					if (Correct == false)
					{
						g_Attempts--;
						Mistakes();
						GuessedLetters(g_Letter);
					}
				}
			}
			else //EASY
			{
				g_Attempts = 10;

				while (g_Check < len)
				{
					if (g_Attempts == 0)
					{
						break;
					}

					UserInterface();//USER-
					InputInterface();//-INTERFACE
					Guess(g_Letter, len);

					if (Correct == false)
					{
						g_Attempts--;
						Mistakes();
						GuessedLetters(g_Letter);
					}
				}
			}
		  }			

	}

	////ENDING SCREEN
	if (g_Check == len)
	{
		system("cls");
		////////////////////// USER INTERFACE /////////////////
		std::cout << "                 -----------------\n";
		std::cout << "                 H A N G   M A N\n";
		std::cout << "                 -----------------\n\n\n\n";

		std::cout << "      " << R3 << R3 << R3 << R3 << R3 << "\n";
		std::cout << "      " << R2 << "   " << R4 << "\n";
		std::cout << "      " << R2 << "   " << R5 << "\n";
		std::cout << "      " << R2 << "  " << (char)g_leftarm << R6 << (char)g_rightarm << "\n";
		std::cout << "      " << R2 << "  " << "" << (char)g_leftleg << (char)g_rightleg << "\n";
		std::cout << "      " << R2;
		std::cout << R1 << R1 << R1 << R1 << R1 << R1 << R1 << "\n";
		std::cout << "\n\n\n";

		std::cout << "      " << StarsArray << "                    " << " Guesses: " << g_Attempts << "\n\n\n\n";

		std::cout << "YOU WIN\n\n\n";
		std::cout << "Congratulations!\n\n";
		system("PAUSE");
		return 0;
	}

	if (g_Attempts == 0)
	{
		system("cls");
		////////////////////// USER INTERFACE /////////////////
		std::cout << "                 -----------------\n";
		std::cout << "                 H A N G   M A N\n";
		std::cout << "                 -----------------\n\n\n\n";

		std::cout << "      " << R3 << R3 << R3 << R3 << R3 << "\n";
		std::cout << "      " << R2 << "   " << R4 << "\n";
		std::cout << "      " << R2 << "   " << R5 << "\n";
		std::cout << "      " << R2 << "  " << (char)g_leftarm << R6 << (char)g_rightarm << "\n";
		std::cout << "      " << R2 << "  " << (char)g_leftleg << (char)g_rightleg << "\n";
		std::cout << "      " << R2;
		std::cout << R1 << R1 << R1 << R1 << R1 << R1 << R1 << "\n";
		std::cout << "\n\n\n";

		std::cout << "      " << StarsArray << "                    " << " Guesses: " << g_Attempts << "\n\n\n\n";

		std::cout << "Word > " << HiddenWord << "\n\n";

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

	std::cout << "      " << R3 << R3 << R3 << R3 << R3 << "\n";
	std::cout << "      " << R2 << "   " << R4 << "\n";
	std::cout << "      " << R2 << "   " << R5 << "\n";
	std::cout << "      " << R2 << "  " << (char)g_leftarm << R6 << (char)g_rightarm << "\n";
	std::cout << "      " << R2 << "  " << "" << (char)g_leftleg << (char)g_rightleg << "\n";
	std::cout << "      " << R2;
	std::cout << R1 << R1 << R1 << R1 << R1 << R1 << R1 << "                   " << "Guessed letters: " << "\n";
	std::cout << "\n\n\n";

	std::cout << "      " << StarsArray << "                    " << " Guesses: " << g_Attempts << "\n\n\n\n";

	//////////////// END OF USER INTERFACE ///////////////
}
void InputInterface()
{
		std::cout << "    " << "Enter a letter: ";
		std::cin >> g_Letter;
}
void HardUserInterface()
{
	R1 = '_';
	R2 = '|';
	R3 = '_';
	R4 = '|';

	system("cls");

	////////////////////// USER INTERFACE /////////////////
	std::cout << "                 -----------------\n";
	std::cout << "                 H A N G   M A N\n";
	std::cout << "                 -----------------\n\n\n\n";

	std::cout << "      " << R3 << R3 << R3 << R3 << R3 << "\n";
	std::cout << "      " << R2 << "   " << R4 << "\n";
	std::cout << "      " << R2 << "   " << R5 << "\n";
	std::cout << "      " << R2 << "  " << (char)g_leftarm << R6 << (char)g_rightarm << "\n";
	std::cout << "      " << R2 << "  " << "" << (char)g_leftleg << (char)g_rightleg << "\n";
	std::cout << "      " << R2;
	std::cout << R1 << R1 << R1 << R1 << R1 << R1 << R1 << "                   " << "Guessed letters: " << "\n\n";
	std::cout << "                                 " << Incorrect;
	std::cout << "\n\n\n";

	std::cout << "      " << StarsArray << "                    " << " Guesses: " << g_Attempts << "\n\n\n\n";

	//////////////// END OF USER INTERFACE ///////////////

}
void StarFun(char buf[], int l)
{

	for (int i = 0; i < l; i++)
	{
		buf[i] = '-';
	}
}
void Guess(char input, int len)//CHECKING LETTER
{
	Correct = false;

	for (int i = 0; i < len; i++)
	{
		if (input == HiddenWord[i])
		{
			if (StarsArray[i] != input)
			{
				StarsArray[i] = input;
				g_Check++;
				Correct = true;
			}
			else//IF LETTER IS REPEATED
			{
				Correct = true;
				break;
			}
		}
	}
}
void Mistakes()
{
  //// 1 MISTAKE
  if (g_Attempts == 9)
  {
	  R1 = '_';
  }

  ////2 MISTAKE
  if (g_Attempts == 8)
  {
	  R2 = '|';
  }

  ////3 MISTAKE
  if (g_Attempts == 7)
  {
	  R3 = '_';
  }

  ////4 MISTAKE
  if (g_Attempts == 6)
  {
	  R4 = '|';
  }

  ////5 MISTAKE
  if (g_Attempts == 5)
  {
	  R5 = '0';
  }

  ////6 MISTAKE
  if (g_Attempts == 4)
  {
	  R6 = '|';
  }

  ////7 MISTAKE
  if (g_Attempts == 3)
  {
	  g_leftleg = 47;
  }

  ////8 MISTAKE
  if (g_Attempts == 2)
  {
	  g_rightleg = 92;
  }

  ////9 MISTAKE
  if (g_Attempts == 1)
  {
	  g_leftarm = 47;
  }

   ////10 MISTAKE
  if (g_Attempts == 0)
  {
	  g_rightarm = 92;
  }

}
void GuessedLetters(char input)
{
	for (int i = 0; i < 20; i++)
	{
		if (input == Incorrect[i])//IF WRONG LETTER REPEATED
		{
			break;
		}

		if (Incorrect[i] != 0)//IF SLOT FOR LETTER IS OCCUPIED
		{
			i++;
		}
		else//WRONG LETTER WILL BE IN FREE SLOT
		{
			Incorrect[i] = input;
			g_Attempts--;
			break;
		}
	}
}