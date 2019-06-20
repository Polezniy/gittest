#include <iostream>
#include <string>
using namespace std;

// Structures

struct Bird
{
	string name;
	string color;
	float strength = 0;
};

struct Slingshot
{
	float slingPower = 0;
};

// Function prototypes
Bird createBird();
void changeBirdByRef(Bird *_bird);
void changeBirdByAddress(Bird &_bird);

Slingshot createSlingshot();

// Main function

int main()
{
	Bird _birbArray[3] = {}; // Array of birds

	Bird birb = createBird(); // Creating a bird instance through function

	_birbArray[0] = birb;
	Slingshot sling = createSlingshot(); // Creating a slingshot through function

	cout << "Angry Birds Console Edition\n\n" << endl;

	cout << "/ / / / Welcome! / / / / \n";
	cout << " Please enter parameters for your bird." << endl;

	cout << " Name -> " << endl;
	cin >> birb.name;

	while (birb.name.size() < 3) // Checks if input for a bird name is shorter than 3 characters.
	{
		
		cout << "\nSorry but you can't put numbers in your birds name, " << endl;
		cout << "and your birds name should be at least 3 characters long." << endl;
		cout << "Please try again." << endl;
		cout << " Name -> " << endl;
		cin >> birb.name;
	}

	cout << " Colour -> " << endl;
	cin >> birb.color;

	cout << " Strength -> " << endl;
	cin >> birb.strength;

	while (birb.strength >= 'A' && birb.strength <= 'z') // If user input is string or letter instead of number.
	{
		cout << "\nSorry but you can't put letters in your birds strength." << endl;
		cout << "Please try again." << endl;
		cout << " Strength -> " << endl;
		cin >> birb.strength;
	}
	
	system("cls");

	cout << "/ / / / Bird Info. / / / /\n" << endl;
	cout << "Name: " << birb.name << endl;
	cout << "Colour: " << birb.color << endl;
	cout << "Strength: " << birb.strength << "\n\n" << endl;

	changeBirdByRef(&birb); // Changing bird instance through pass-by-reference function
	cout << "*UPDATE*\n" << endl;
	cout << "New bird info.\n" << endl;
	cout << "Name: " << birb.name << endl;
	cout << "Colour: " << birb.color << endl;
	cout << "Lifespan: " << birb.strength << "\n\n" << endl;

	changeBirdByAddress(birb); // Changing bird instance through pass-by-address function
	cout << "*UPDATE*\n" << endl;
	cout << "New bird info.\n" << endl;
	cout << "Name: " << birb.name << endl;
	cout << "Colour: " << birb.color << endl;
	cout << "Lifespan: " << birb.strength << "\n\n" << endl;

	cout << "Now please enter the parameters for slingshot." << endl;

	cout << " Power -> " << endl;
	cin >> sling.slingPower;

	if (cin.fail()) // If the cin function will fail it will display an error. 
	{
		cout << "Oops. A wild error appeared out of nowhere." << endl;
	}

	cout << "/ / / / Slingshot info. / / / /\n" << endl;
	cout << "Slingshot power: " << sling.slingPower << "\n" << endl;
	
	system("pause");

	return 0;
}

Bird createBird() // Function that creates a Bird instance
{
	Bird _bird;
	
	return _bird;
}

void changeBirdByRef(Bird *_bird) // Pass-by-reference
{
	cout << "Changing bird Info\n" << endl;

	_bird->color = "new colour";
	_bird->strength = 100;
	_bird->name = "new name";

	cout << "New info" << endl;
}

void changeBirdByAddress(Bird &_bird) // Pass-by-address
{
	_bird.color = "ADDRESS COLOR";
	_bird.strength = 0;
	_bird.name = "ADDRESS NAME";
}

Slingshot createSlingshot()
{
	Slingshot _sling;

	//_sling.power = 10;

	return _sling;
}

void changeSlingByRef(Slingshot *_sling)
{
	_sling->slingPower = 100;
}

void changeSlingByAddress(Slingshot &_sling)
{
	_sling.slingPower = 100;
}