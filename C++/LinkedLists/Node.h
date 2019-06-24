#pragma once
#include "Cube.h"

struct Node //Node structure
{
public:
	Cube data; //A data inside node
	Node *next; //A pointer to next node
};
