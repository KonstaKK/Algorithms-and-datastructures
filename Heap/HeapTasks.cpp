#include "Heap.h"

int main() {
	// 17, 11, 6, 14, 22, 8, 1, 16, 10, 19, 12, 3, 5, 15, 13
	Heap myHeap;

	myHeap.insert(17);
	myHeap.insert(11);
	myHeap.insert(6);
	myHeap.insert(14);
	myHeap.insert(22);
	myHeap.insert(8);
	myHeap.insert(1);
	myHeap.insert(16);
	myHeap.insert(10);
	myHeap.insert(19);
	myHeap.insert(12);
	myHeap.insert(3);
	myHeap.insert(5);
	myHeap.insert(15);
	myHeap.insert(13);

	myHeap.print();
}