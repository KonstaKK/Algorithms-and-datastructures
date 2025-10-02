#pragma once
#include "Node.h"

class LinkedList
{
public:
	Node* pHead;

	bool Create();
	bool Add(int data);
	void Print();

	//Constructor
	LinkedList() : pHead(nullptr) {}
};

