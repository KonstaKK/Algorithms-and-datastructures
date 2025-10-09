#include "LinkedList.h"
#include <iostream>
#include <stack>

// Exists so creating the head pointer code doesn't need to be copied a gazillion times
bool LinkedList::Create(int data) {
	if (nullptr == pHead) {
		Node* pNewNode = new Node(data);	// luotiin uusi node arvolla "data"
		pHead = pNewNode;					// head-pointer osoittaa uuteen nodeen
		return true;
	}
	return false;
}

bool LinkedList::Add(int data) {
	// Tyhjä lista = luodaan node ja laitetaan headi osoittamaan uuteen nodeen

	if (Create(data)) {
		return true;
	} // Lisää aina alkuun ( 0(1)-aikainen
	else {
		Node* pNewNode = new Node(data);	// luotiin uusi node arvolla "data"
		pNewNode->Next = pHead;				// asetettiin uuden noden next-nodeksi vanha head
		pHead = pNewNode;					// head-pointer osoittaa uuteen nodeen
		return true;
	}

	return false;
}

// Task 5.1.

void LinkedList::Insert(int value) {
	if (!Create(value)) {
		Node* pNewNode = new Node(value);
		if (nullptr != pHead->Next) {
			pNewNode->Next = pHead->Next;
		}
		pHead->Next = pNewNode;
	}
}

void LinkedList::Print() {
	if (IsEmpty()) {
		std::cout << "The list is empty" << std::endl;
		return;
	}

	Node* pCurrent = pHead;
	
	while (nullptr != pCurrent) {
		std::cout << "Data: " << pCurrent->Data << std::endl;
		pCurrent = pCurrent->Next;
	}
}

void LinkedList::InsertEnd(int value) {
	if (!Create(value)) {
		Node* currentNode = pHead;
		Node* pNewNode = new Node(value);
		while (nullptr != currentNode->Next) {
			currentNode = currentNode->Next;
		}
		currentNode->Next = pNewNode;
	}
}

bool LinkedList::IsEmpty() {
	if (nullptr == pHead) {
		return true;
	}
	return false;
}

// Task 5.2.

bool LinkedList::Find(int value) {
	Node* currentNode = pHead;
	while (nullptr != currentNode) {
		if (currentNode->Data == value) {
			return true;
		}
		currentNode = currentNode->Next;
	}
	return false;
}

bool LinkedList::Delete(int value) {
	Node* currentNode = pHead;
	Node* previousNode = nullptr;
	while (nullptr != currentNode) {
		if (currentNode->Data == value) {
			if (nullptr != previousNode) {
				previousNode->Next = currentNode->Next;
			}
			if (currentNode == pHead) {
				pHead = currentNode->Next;
			}
			delete(currentNode);
			return true;
		}
		if (nullptr == previousNode) {
			previousNode = currentNode;
		}
		else {
			previousNode = previousNode->Next;
		}
		currentNode = currentNode->Next;
	}
	return false;
}

// Challenge

void LinkedList::Reverse() {
	std::stack<Node*> nodeStack;
	Node* currentNode = pHead;
	while (nullptr != currentNode->Next) {
		nodeStack.push(currentNode);
		currentNode = currentNode->Next;
	}
	pHead = currentNode;
	while (!nodeStack.empty()) {
		currentNode->Next = nodeStack.top();
		nodeStack.pop();
		currentNode = currentNode->Next;
	}
	currentNode->Next = nullptr;
}