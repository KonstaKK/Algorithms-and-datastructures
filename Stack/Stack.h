#pragma once
#include "Node.h"
#include <iostream>

template <class T>
class Stack {
public:
	Stack() : Head(nullptr) {}
	~Stack() {}

	void Push(T value) {
		Node<T>* newNode = new Node<T>(value);

		newNode->Next = Head;
		Head = newNode;
	}

	T Pop() {
		/*if (IsEmpty()) {
			return -1;
		}*/

		Node<T>* poppedNode = Head;
		T value = poppedNode->Data;

		Head = poppedNode->Next;

		delete(poppedNode);

		std::cout << "Popped data: " << value << std::endl;
		return value;
	}

	bool IsEmpty() {
		return nullptr == Head;
	}

	void Print() {
		if (IsEmpty()) {
			std::cout << "The stack is empty" << std::endl;
			return;
		}

		Node<T>* currentNode = Head;

		while (nullptr != currentNode) {
			std::cout << "Data: " << currentNode->Data << std::endl;
			currentNode = currentNode->Next;
		}
	}

private:
	Node<T>* Head;
};