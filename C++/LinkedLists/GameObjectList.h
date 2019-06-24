#pragma once
#include "iostream"
#include "Node.h"

using namespace std;
class GameObjectList
{
public:

	GameObjectList(void) // Constructor
	{
		head == NULL; // When the list first constructed it points to nothing because there is no nodes yet created
					  // And it makes sure that there is no nodes created yet
	}
	~GameObjectList(void); // Destructor

	bool IsEmpty() // Member function
	{
		return head == NULL; // Returns true if the head is pointing to null, thus the list is empty
	}

	Node *InsertNode(int position, Cube data); // Insert a node with "char data" at the "position"
											   // If insertion is succesfull return the pointer to the inserted node
	int FindNode(Cube data); // Find a node with a value equal to "data" 
	int DeleteNode(Cube data); // Delete the node with a value equal to "data"
	void DisplayList(void); // Displaying the full list of nodes in the list

private:
	Node* head; // A pointer to the first node in the list
};