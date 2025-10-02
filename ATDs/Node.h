#pragma once
class Node
{
public:
	int Data;
	Node* Next;

	//Constructor
	Node(int val) : Data(val), Next(nullptr) {};
};

