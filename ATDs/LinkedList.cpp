#include "LinkedList.h"
#include <iostream>

bool LinkedList::Add(int data) {
	// Tyhjä lista = luodaan node ja laitetaan headi osoittamaan uuteen nodeen

	if (nullptr == pHead) {
		Node* pNewNode = new Node(data);	// luotiin uusi node arvolla "val"
		pHead = pNewNode;					// head-pointer osoittaa uuteen nodeen
		return true;
	} // Lisää aina alkuun ( 0(1)-aikainen
	else {
		Node* pNewNode = new Node(data);	// luotiin uusi node arvolla "val"
		pNewNode->Next = pHead;				// asetettiin uuden noden next-nodeksi vanha head
		pHead = pNewNode;					// head-pointer osoittaa uuteen nodeen
		return true;
	}

	return false;
}

// Tulostaa listan sisällön kokonaan
void LinkedList::Print() {
	Node* pCurrent = pHead;
	
	while (nullptr != pCurrent) {
		std::cout << pCurrent->Data << std::endl;
		pCurrent = pCurrent->Next;
	}
}