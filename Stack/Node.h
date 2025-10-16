#pragma once

template <class T>
class Node {
public:
	T Data;
	Node<T>* Next;

	//Constructor
	Node(T val) : Data(val), Next(nullptr) {};
};

