#include "iostream"
#include "GameObjectList.h"

int main()
{
	GameObjectList list;
	Cube c1, c2;

	list.InsertNode(0, c1);
	list.InsertNode(1, c2);

	list.DisplayList();

	list.DeleteNode(c2);
	list.DisplayList;

	return 0;
}