#include "GameObjectList.h"

GameObjectList::~GameObjectList()
{
	// Step through the list and delete each node one by one
	Node* currNode = head;
	Node* nextNode = NULL;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

Node *GameObjectList::InsertNode(int position, Cube data)
{
	// Precautions for node insertion
	if (position < 0) return NULL; // Can't insert a node if the position given is negative

	int index = 0;

	Node* currentNode = head;

	while (currentNode && position > index)
	{
		currentNode = currentNode->next; // First head then first node
		index++;
	}

	if (index > 0 && currentNode == NULL) return NULL; // If reached the end

	//Actual node insertion
	Node* newNode = new Node();
	newNode->data = data;

	if (position == 0) // First position of the list
	{
		newNode->next = head; // Gives a pointer to itself to a "head" node
		head = newNode; // Becomes a new "head" node
	}
	else // If the desired position is not first
	{
		newNode->next = currentNode->next; // Gives a pointer to itself to a current last node
		currentNode->next = newNode; // And becomes a new current node
	}
	return newNode;
}

int GameObjectList::DeleteNode(Cube data)
{
	// Loop through the list to find the node with its data which is equal to "data"
	Node* prevNode = NULL;
	Node* currNode = head;
	int currIndex = 1;

	while (currNode && currNode->data != data)
	{
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}

	// Deletion of found node
	if (currNode)
	{
		if (prevNode)
		{
			prevNode->next = currNode->next;
			delete currNode;
		}
		else
		{
			head = currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	return 0;
}

void GameObjectList::DisplayList()
{
	int num = 0;
	Node* currNode = head;

	while (currNode != NULL)
	{
		cout << "data" << currNode->data << endl;
		currNode = currNode->next;
		num++;
	}
}