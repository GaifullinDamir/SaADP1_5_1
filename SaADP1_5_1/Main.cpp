#include <iostream>
#include "Node.h"
#include "UserInterface.h"

int main()
{
	Node* pRoot;
	init(pRoot);
	workWithUser(pRoot);
	treeClearMemory(pRoot);
}