#pragma once
#include "Node.h"
#include <iostream>

class BST
{
public:
	Node* Root;

	// 7.1.
	BST() : Root(nullptr) {};

	~BST() { Root = nullptr; }

	void insert(int value) {
		// If empty
		if (nullptr == Root) {
			// create a new node and assign as new:
			Root = new Node(value);
			//std::cout << "Node with the value " << Root->Data << " added as root" << std::endl;
		}
		else {
			// Set up a current pointer to a node
			Node* currentNode = Root;	// Start at the root
			Node* parentNode = nullptr;	// parent pointer

			// Traverse the tree until current is null
			// ==> we have found the spot
			while (nullptr != currentNode) {
				parentNode = currentNode; // Update parent
				// Is new value bigger or smaller than current

				// Smaller = go left
				if (value < currentNode->Data) {
					currentNode = currentNode->Left;
				}
				// Bigger / Equal = go right
				else {
					currentNode = currentNode->Right;
				}
			}
			// Found the spot, baby
			// create node with the new value
			Node* newNode = new Node(value);
			// check which child node to attach it to
			if (value < parentNode->Data) {
				parentNode->Left = newNode;
			}
			else {
				parentNode->Right = newNode;
			}

			//std::cout << "Node with the value " << newNode->Data << " added as a child of " << parentNode->Data << std::endl;
		}
		//Root = insertRec(Root, value);
	}

	// The tree gets printed sideways
	// ChatGPT was used for this function
	void print(Node* current, std::string prefix = "", bool isLeft = true) {
		if (current == nullptr)
			return;

		if (current->Right) {
			if (current == Root) {
				print(current->Right, prefix + "    ", false);
			}
			else {
				print(current->Right, prefix + (isLeft ? "|   " : "    "), false);
			}
		}

		std::cout << prefix;
		if (current != Root) {
			std::cout << (isLeft ? "\\" : "/");
		}
		std::cout << current->Data << std::endl;

		if (current->Left) {
			print(current->Left, prefix + (isLeft ? "    " : "|   "), true);
		}
	}

	int countNodes(Node* current) {
		if (nullptr == current) {
			return 0;
		}

		return countNodes(current->Left) + countNodes(current->Right) + 1;
	}

	int countLeaves(Node* current) {
		if (nullptr == current) {
			return 0;
		}

		if (nullptr == current->Left && nullptr == current->Right) {
			return 1;
		}

		return countLeaves(current->Left) + countLeaves(current->Right);
	}

	// 7.2.
	bool deleteNode(int key) {
		Node* currentNode = Root;	// Start at the root
		Node* parentNode = nullptr;	// parent pointer

		// Traverse the tree until current is null
		// ==> we have found the spot
		while (nullptr != currentNode && key != currentNode->Data) {
			parentNode = currentNode; // Update parent

			// Smaller = go left
			if (key < currentNode->Data) {
				currentNode = currentNode->Left;
			}
			// Bigger = go right
			else if (key > currentNode->Data) {
				currentNode = currentNode->Right;
			}
		}
		// Found the spot, baby
		// just to double check
		if (nullptr == currentNode) {
			std::cout << "The node was not found" << std::endl;
			return false;
		}
		// Now it's deletion time
		
		Node* newNode;
		// Left
		if (currentNode->Data < parentNode->Data) {
			if (nullptr != currentNode->Right) {
				newNode = currentNode->Right;
				parentNode->Left = newNode;
				newNode->Left = currentNode->Left;
			}
			else if (nullptr != currentNode->Left) {
				newNode = currentNode->Left;
				parentNode->Left = newNode;
			}
			else {
				parentNode->Left = nullptr;
			}
		}
		// Right
		else {
			if (nullptr != currentNode->Right) {
				newNode = currentNode->Right;
				parentNode->Right = newNode;
				newNode->Left = currentNode->Left;
			}
			else if (nullptr != currentNode->Left) {
				newNode = currentNode->Left;
				parentNode->Right = newNode;
			}
			else {
				parentNode->Right = nullptr;
			}
		}
		delete(currentNode);
		return true;
	}
};