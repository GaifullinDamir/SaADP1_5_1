#include <iostream>
#include "Node.h"

void init(Node*& pRoot) { pRoot = nullptr; }
bool isEmpty(Node* pRoot) { return (pRoot == nullptr); }

void addNode(Node*& pCurrent, int n)
{
	Node* pTemporary;
	int nLeft, nRight;
	if (n == 0)  pCurrent = nullptr;								//���� ������ ��� ���������� ���, ��������� ������ ������
	else
	{
		nLeft = n / 2;												//���-�� ������ �����
		nRight = n - nLeft - 1;										//���-�� ������ ������
		pTemporary = new Node;										//�������� ����� ������
		pTemporary->data = rand() % 99;								//���������� ���-�� ����� ���� ��������� ������ � ��������� 0-99
		addNode(pTemporary->left, nLeft);							//���������� ������� ����� ���������
		addNode(pTemporary->right, nRight);							//���������� ������� ������ ���������
		pCurrent = pTemporary;										//���������� ����� ���������� �����
	}
}

void showForward(Node* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		for (int i = 0; i < level; i++) { std::cout << "     "; }	//��� ������ ���-�� level � ����� for ��������� �����-� �������
		std::cout << pCurrent->data << std::endl; level++;			//����� �� ������� ���-�� ����� ���� � ���������� ������ �� 1
		showForward(pCurrent->left, level);							//����������� ����� ������� ��� ������ ���������
		showForward(pCurrent->right, level);						//����������� ����� ������� ��� ������� ���������
	}
}

void showSymmetrical(Node* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		for (int i = 0; i < level; i++) { std::cout << "     "; }
		showSymmetrical(pCurrent->left, level);
		std::cout << pCurrent->data << std::endl; level++;
		showSymmetrical(pCurrent->right, level);
	}
}

void showReverseSymmetrical(Node* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		for (int i = 0; i < level; i++) { std::cout << "     "; }
		showReverseSymmetrical(pCurrent->left, level);
		showReverseSymmetrical(pCurrent->right, level);
		std::cout << pCurrent->data << std::endl; level++;
	}
}
