#pragma once
#include "Node.h"

class LinkedList
{
public:
	Node* pHead;

	bool Create(int data);
	bool Add(int data);
	void Insert(int value);
	void Print();
	void InsertEnd(int value);
	bool IsEmpty();

	bool Find(int value);
	bool Delete(int value);

	void Reverse();

	//Constructor
	LinkedList() : pHead(nullptr) {}
};

