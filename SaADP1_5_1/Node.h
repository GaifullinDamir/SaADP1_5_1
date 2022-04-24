#pragma once
struct Node
{
	int data;
	Node* left, * right;
};

void init(Node*& pRoot);
bool isEmpty(Node* pRoot);
void addNode(Node*& pRoot, int n);
void showForward(Node* pRoot, int level);
void showSymmetrical(Node* pRoot, int level);
void showReverseSymmetrical(Node* pCurrent, int level);
void treeClearMemory(Node*& pCurrent);