#include "Heap.h"
#include <chrono>

int main() {

	// task 7.1.
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

	std::cout << std::endl;

	myHeap.delMin();

	// task 7.2.
	Heap heap100k;
	Heap heap1mil;
	Heap heap10mil;

	std::cout << std::endl;
	std::cout << "100 000 element heap timing starts" << std::endl;
	auto start1 = std::chrono::steady_clock::now();
	for (int i = 0; i < 100000; ++i) {
		heap100k.insert(rand() % 100);
	}
	auto end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "1 000 000 element heap timing starts" << std::endl;
	auto start2 = std::chrono::steady_clock::now();
	for (int i = 0; i < 1000000; ++i) {
		heap1mil.insert(rand() % 100);
	}
	auto end2 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end2 - start2).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "10 000 000 element heap timing starts" << std::endl;
	auto start3 = std::chrono::steady_clock::now();
	for (int i = 0; i < 10000000; ++i) {
		heap10mil.insert(rand() % 100);
	}
	auto end3 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end3 - start3).count() << " microseconds" << std::endl;
}