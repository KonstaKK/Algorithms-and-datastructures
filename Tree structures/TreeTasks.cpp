#include "BST.h"

int main() {
	/*Stack<int> myStack;
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
	myStack.Print();*/

	// Tree: 15 14 10 8 4 23 23 19 23 8 19 24 21
	BST myTree;

	myTree.insert(15);
	myTree.insert(14);
	myTree.insert(10);
	myTree.insert(8);
	myTree.insert(4);
	myTree.insert(23);
	myTree.insert(23);
	myTree.insert(19);
	myTree.insert(23);
	myTree.insert(8);
	myTree.insert(19);
	myTree.insert(24);
	myTree.insert(21);

	myTree.print(myTree.Root);
	std::cout << std::endl;

	std::cout << "The tree has: " << myTree.countNodes(myTree.Root) << " Nodes." << std::endl;
	std::cout << std::endl;
	std::cout << "The tree has: " << myTree.countLeaves(myTree.Root) << " Leaves." << std::endl;
	std::cout << std::endl;
	std::cout << "Deleting node with value 24: " << myTree.deleteNode(24) << std::endl;
	myTree.print(myTree.Root);
	std::cout << std::endl;
	std::cout << "Deleting node with value 10: " << myTree.deleteNode(10) << std::endl;
	myTree.print(myTree.Root);
	std::cout << std::endl;
	std::cout << "Deleting node with value 19: " << myTree.deleteNode(19) << std::endl;
	myTree.print(myTree.Root);
	std::cout << std::endl;
	std::cout << "Deleting node with value 8: " << myTree.deleteNode(8) << std::endl;
	myTree.print(myTree.Root);
}