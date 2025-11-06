#include "Heap.h"
#include <iostream>

Heap::Heap() {
	for (int i = 0; i <= MAX_HEAP_SIZE; i++) {
		heapArray[i] = 0;
	}
}

bool Heap::insert(int value) {
	if (heapArray[0] < MAX_HEAP_SIZE) {
		// Insert the new value
		int heapSize = heapArray[0];
		// 1. Insert new value at the end
		heapArray[heapSize + 1] = value;

		// 2. Lift the value up to the correct spot
		//    -	Stop when parent is smaller
		//		OR when we are at the root
		//	<=> Continue when currentIndex > 1 AND
		//		heapArray[parentIndex] > value
		int currentIndex = heapSize + 1;
		int parentIndex = currentIndex / 2;
		while (currentIndex > 1 && heapArray[parentIndex] > value) {
			// Swap values and update indices
			// - we can overwrite value at currentIndex
			heapArray[currentIndex] = heapArray[parentIndex];
			// - update value at parentIndex
			heapArray[parentIndex] = value;

			// - update indices
			currentIndex = parentIndex;
			parentIndex = currentIndex / 2;
		}
		// 3. Grow heap size
		heapArray[0]++;
		return true;
	}
	else
		return false;
}

void Heap::print() {
	std::cout << "Heap size: " << heapArray[0] << std::endl;
	std::cout << "[";
	for (int i = 1; i < heapArray[0]; i++) {
		std::cout << heapArray[i] << ", ";
	}
	std::cout << heapArray[heapArray[0]];
	std::cout << "]" << std::endl;
}