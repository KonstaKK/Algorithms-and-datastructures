#pragma once
#include <iostream>
#include <iomanip>
#define MAX_HEAP_SIZE 100

class Heap
{
public:
	Heap();
	~Heap() {}

	bool insert(int value);
	void delMin();
	void sort(int currentIndex, int firstChildIndex, int secondChildIndex);
	void print();

private:
	int heapArray[MAX_HEAP_SIZE + 1];
};

