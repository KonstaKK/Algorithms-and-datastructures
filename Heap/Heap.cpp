#include "Heap.h"

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

void Heap::delMin() {
	heapArray[1] = heapArray[heapArray[0]];
	heapArray[heapArray[0]] = 0;
	heapArray[0] -= 1;
	print();
	std::cout << std::endl;
	
	int heapSize = heapArray[0];
	int currentIndex = 1;
	int firstChildIndex = currentIndex * 2;
	int secondChildIndex = firstChildIndex + 1;
	while (currentIndex < heapSize) {
		sort(currentIndex, firstChildIndex, secondChildIndex);
		currentIndex += 1;
		firstChildIndex = currentIndex * 2;
		secondChildIndex = firstChildIndex + 1;
	}
	std::cout << std::endl;
	print();
}

void Heap::sort(int currentIndex, int firstChildIndex, int secondChildIndex) {
	//std::cout << "Index: " << heapArray[currentIndex] << " | First child: " << heapArray[firstChildIndex] << " | Second child: " << heapArray[secondChildIndex] << std::endl;

	if (heapArray[currentIndex] > heapArray[firstChildIndex] && heapArray[firstChildIndex] > 0) {
		std::cout << "Swapping " << heapArray[currentIndex] << " with " << heapArray[firstChildIndex] << std::endl;
		int temp = heapArray[currentIndex];
		heapArray[currentIndex] = heapArray[firstChildIndex];
		heapArray[firstChildIndex] = temp;
	}

	if (heapArray[currentIndex] > heapArray[secondChildIndex] && heapArray[secondChildIndex] > 0) {
		std::cout << "Swapping " << heapArray[currentIndex] << " with " << heapArray[secondChildIndex] << std::endl;
		int temp = heapArray[currentIndex];
		heapArray[currentIndex] = heapArray[secondChildIndex];
		heapArray[secondChildIndex] = temp;
	}
}

void Heap::print() {
	std::cout << "Heap size: " << heapArray[0] << std::endl;
	std::cout << "[";
	for (int i = 1; i < heapArray[0]; i++) {
		std::cout << heapArray[i] << ", ";
	}
	std::cout << heapArray[heapArray[0]];
	std::cout << "]" << std::endl;

	// Attempted to upgrade it to show it as a tree using ChatGPT.
	// Nothing came out of it

	//int n = heapArray[0]; // number of elements
	//if (n == 0) {
	//	std::cout << "Heap is empty.\n";
	//	return;
	//}

	//std::cout << "Heap size: " << n << std::endl;

	//int level = 0;
	//int index = 1;
	//int width = 4 * (int)std::pow(2, std::floor(std::log2(n))); // for spacing

	//while (index <= n) {
	//	int levelCount = std::pow(2, level); // nodes at this level
	//	int spaceBetween = width / (levelCount + 1);

	//	// print nodes
	//	for (int i = 0; i < levelCount && index <= n; ++i, ++index) {
	//		std::cout << std::setw(spaceBetween) << heapArray[index];
	//	}
	//	std::cout << std::endl;

	//	// print connecting slashes if not last level
	//	if (index <= n) {
	//		int slashCount = std::pow(2, level - 1);
	//		for (int i = 0; i < levelCount && (2 * (index - levelCount + i)) <= n; ++i) {
	//			std::cout << std::setw(spaceBetween / 2) << "/";
	//			std::cout << std::setw(spaceBetween / 2) << "\\";
	//		}
	//		std::cout << std::endl;
	//	}

	//	++level;
	//}
}