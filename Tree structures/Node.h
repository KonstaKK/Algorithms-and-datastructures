#pragma once

class Node {
public:
	int Data;
	Node* Left;
	Node* Right;

	//Constructor
	Node(int val) : Data(val), Left(nullptr), Right(nullptr) {};
};

