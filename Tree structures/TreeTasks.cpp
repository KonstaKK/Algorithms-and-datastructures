#include "Stack.h"
#include <iostream>

int main() {
	Stack<int> myStack;
	Stack<int> secondaryStack;

	for (int i = 10; i > 0; i--) {
		myStack.Push(i);
	}

	std::cout << "First stack:" << std::endl;
	myStack.Print();

	std::cout << std::endl;

	for (int i = 10; i > 0; i--) {
		secondaryStack.Push(myStack.Pop());
	}

	std::cout << std::endl;

	std::cout << "Second stack:" << std::endl;
	secondaryStack.Print();

	std::cout << std::endl;
	std::cout << "First stack:" << std::endl;
	myStack.Print();
}