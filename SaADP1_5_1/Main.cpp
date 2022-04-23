#include <iostream>
#include "Node.h"
#include "UserInterface.h"

int main()
{
	Node* pRoot = new Node;
	init(pRoot);
	workWithUser(pRoot);
}