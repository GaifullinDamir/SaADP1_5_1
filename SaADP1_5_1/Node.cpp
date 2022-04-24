#include <iostream>
#include "Node.h"

void init(Node*& pRoot) { pRoot = nullptr; }
bool isEmpty(Node* pRoot) { return (pRoot == nullptr); }

void addNode(Node*& pCurrent, int n)
{
	Node* pTemporary;
	int nLeft, nRight;
	if (n == 0)  pCurrent = nullptr;								//Если вершин для размещения нет, формируем пустую ссылку
	else
	{
		nLeft = n / 2;												//Кол-во вершин слева
		nRight = n - nLeft - 1;										//Кол-во вершин справа
		pTemporary = new Node;										//Создание корня дерева
		pTemporary->data = rand() % 99;								//Заполнение инф-ой части узла случайным числом в диапозоне 0-99
		addNode(pTemporary->left, nLeft);							//Рекурсивно создаем левое поддерево
		addNode(pTemporary->right, nRight);							//Рекурсивно создаем правое поддерево
		pCurrent = pTemporary;										//Возвращаем адерс созданного корня
	}
}

void showForward(Node* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		for (int i = 0; i < level; i++) { std::cout << "     "; }	//При помощи пер-ой level и цикла for реализуем необх-е отступы
		std::cout << pCurrent->data << std::endl; level++;			//Вывод на консоль инф-ой части узла и увеличение уровня на 1
		showForward(pCurrent->left, level);							//Рекурсивный вызов функции для левого поддерева
		showForward(pCurrent->right, level);						//Рекурсивный вызов функции для правого поддерева
	}
}

void showSymmetrical(Node* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		level++;
		showSymmetrical(pCurrent->left, level);
		for (int i = 0; i < level-1; i++) { std::cout << "     "; }
		std::cout << pCurrent->data << std::endl; 
		showSymmetrical(pCurrent->right, level);
	}
}

void showReverseSymmetrical(Node* pCurrent, int level)
{
	if (pCurrent != nullptr)
	{
		level++;
		showReverseSymmetrical(pCurrent->right, level);
		for (int i = 0; i < level-1; i++) { std::cout << "     "; }
		std::cout << pCurrent->data << std::endl;
		showReverseSymmetrical(pCurrent->left, level);
	}
}

void treeClearMemory(Node*& pCurrent)
{
	if (pCurrent != nullptr)
	{
		treeClearMemory(pCurrent->left);								//Очистка памяти при помощи обратного обхода
		treeClearMemory(pCurrent->right);
		delete pCurrent;
	}
}