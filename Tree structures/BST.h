#pragma once
#include "Node.h"
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
		}
		else {
			// Set up a current pointer to a node
			Node* currentNode = Root;	// Start at the root
			Node* parentNode = nullptr;	// parent pointer

			// Traverse the tree until current is null
			// ==> we have found the spot, baby
			while (nullptr != currentNode) {
				parentNode = currentNode; // Update parent
				// Is new value bigger or smaller than current

				// Smaller = go left
				if (value < currentNode->Data) {
					currentNode = currentNode->Left;
				}

				// Bigger = go right
				else {
					currentNode = currentNode->Right;
				}
			}
			// Found the spot
			// create node with the new value
			Node* newNode = new Node(value);
			// check which child node to attach it to
			if (value < newNode->Data) {
				parentNode->Left = newNode;
			}
			else {
				parentNode->Right = newNode;
			}
		}

		//Root = insertRec(Root, value);
	}
};

