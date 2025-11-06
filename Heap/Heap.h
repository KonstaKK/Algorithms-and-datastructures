#pragma once
#define MAX_HEAP_SIZE 100

class Heap
{
public:
	Heap();
	~Heap() {}

	bool insert(int value);
	void print();

private:
	int heapArray[MAX_HEAP_SIZE + 1];
};

