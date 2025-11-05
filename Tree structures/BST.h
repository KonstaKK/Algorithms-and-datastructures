#pragma once
#include "Node.h"
#include <iostream>

class BST
{
public:
	Node* Root;

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
			if (value < newNode->Data) {
				parentNode->Left = newNode;
			}
			else {
				parentNode->Right = newNode;
			}

			//std::cout << "Node with the value " << newNode->Data << " added as a child of " << parentNode->Data << std::endl;
		}
		//Root = insertRec(Root, value);
	}

	// Tree: 15 14 10 8 4 23 23 19 23 8 19 24 21
	void print(Node* current, int space = 0, int indent = 4) {
		if (current == nullptr)
			return;

		// Increase distance between levels
		space += indent;

		// Print right child first
		print(current->Right, space);

		// Print current node after spaces
		std::cout << std::endl;
		for (int i = indent; i < space; i++)
			std::cout << " ";
		std::cout << current->Data << "\n";

		// Print left child
		print(current->Left, space);
	}
	// ChatGPT was used

	void countNodes() {
		//return countNodes(T.left) + countNodes(T.right) + 1;
	}

	void countLeaves() {

	}
};

