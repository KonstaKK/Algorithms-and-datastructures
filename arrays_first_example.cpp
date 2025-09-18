//------------------------------------------------------
// Included headers for printing
//------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <chrono>

//------------------------------------------------------
// Some helpful constants you can use
//------------------------------------------------------
#define SIZE 10
#define OB_INDEX 20
#define BIG_SIZE 1000000 // 1 million integers ~4MB
#define VERY_BIG_SIZE 4000000 // 4 million integers ~16MB

//------------------------------------------------------
// Helper functions 
//------------------------------------------------------
void allocateLargeArray() {
    int big_array[BIG_SIZE];

    for (int i = 0; i < BIG_SIZE; i++) {
        std::cout << "Big array[" << i << "] = " << big_array[i] << " addr: " << &big_array[i] << std::endl;
    }

    std::cout << "Size of big array (int): " << sizeof(big_array) << std::endl;

    // Deallocate the memory
    delete[] big_array;

    return;
}

bool doubleStorage(int*& array, int& currentSize) {
    size_t new_size = currentSize * 2;
    int* alloc_array = new (std::nothrow) int[new_size];
    if (!alloc_array) {
        std::cout << "Failure " << std::endl;
        return false;
    }
    for (int i = 0; i < currentSize; ++i) {
        alloc_array[i] = array[i];
    }

    delete[] array;
    array = alloc_array;
    currentSize = new_size;

    std::cout << "New array size doubled" << std::endl;
    for (int i = 0; i < new_size; i++) {
        std::cout << "Big array[" << i << "] = " << array[i] << " addr: " << &array[i] << std::endl;
    }
    std::cout << std::endl;
    return true;
}


//------------------------------------------------------
// Main program
//------------------------------------------------------
/*
int main() {

    std::cout << "Demonstrating C-style arrays and bounds." << std::endl;

    //------------------------------------------------------
    // Part 1: Static Array Fundamentals and Stack Behavior
    //------------------------------------------------------

    // 1. Automatic 10-element local array without initialization
    int array[SIZE];
    std::cout << "Created 10-element array (uninitialized)." << std::endl;
    std::cout << std::endl;

    // 2. Print the values and memory addresses of the first and last elements (this prints all).
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Array[" << i << "] = " << array[i] << " addr: " << &array[i] << std::endl;
    }
    std::cout << "Size of our array (int): " << sizeof(array) << std::endl;
    std::cout << "Size of int: " << sizeof(int) << std::endl;
    std::cout << "Size of long long: " << sizeof(long long) << std::endl;
    std::cout << "Size of bool: " << sizeof(bool) << std::endl;
    std::cout << std::endl;

    // 3. Initialize the array elements to zero. Print again.
    std::cout << "Initialized the elements in same array." << std::endl;
    for (int i = 0; i < SIZE; i++) {
        array[i] = 0;
        std::cout << "Array[" << i << "] = " << array[i] << " addr: " << &array[i] << std::endl;
    }
    std::cout << std::endl;

    // BONUS: Fill the array with random integer values ranging from 0 to 100.
    std::cout << "BONUS: Filled the elements with integer values 0-100." << std::endl;
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % 101;
        std::cout << "Array[" << i << "] = " << array[i] << std::endl;
    }
    std::cout << std::endl;

    // 4. Attempt to access an element beyond the array's bounds (undefined behavior)
    std::cout << "Element beyond array's bounds: " << array[SIZE] << std::endl;
    std::cout << std::endl;

    // 5. Create a function that allocates a very large static integer array. 
    // allocateLargeArray() implemented in the beginning of main.cpp

    // 6. Call the function.
    std::cout << "Calling allocateLargeArray" << std::endl;
    //allocateLargeArray();
    std::cout << std::endl;
    
    // 7. Observe and explain the behavior.
    std::cout << "The big array has 1000000 values and Windows runs out of stack size" << std::endl;
    std::cout << "Thus the code crashes" << std::endl;
    std::cout << std::endl << std::endl;


    //------------------------------------------------------
    // Part 2: Dynamic Arrays 
    //------------------------------------------------------

     std::cout << "Demonstrating dynamic memory allocation for arrays." << std::endl;
     std::cout << std::endl;

    // 1. Dynamically allocate an array of 10 integers using new.
    int* new_array = new int[SIZE];

    // 2. Print the values and memory addresses of all elements.
    for (int i = 0; i < SIZE; i++) {
        std::cout << "Big array[" << i << "] = " << new_array[i] << " addr: " << &new_array[i] << std::endl;
    }
    std::cout << std::endl;

    // 3. Resize the array to 20 elements.
    int new_size = SIZE * 2;
    int* alloc_array = new int[new_size];

    memcpy(alloc_array, new_array, SIZE * sizeof(int));

    delete[] new_array;
    new_array = alloc_array;

    std::cout << "New array resized" << std::endl;
    for (int i = 0; i < new_size; i++) {
        std::cout << "Big array[" << i << "] = " << new_array[i] << " addr: " << &new_array[i] << std::endl;
    }
    std::cout << std::endl;

    // BONUS: Double the size of the dynamic array when we run out of space.
    doubleStorage(new_array, new_size);
    delete[] new_array;


    //------------------------------------------------------
    // Part 3: Discussion 
    //------------------------------------------------------

    // 1. The difference between the stack and the heap
    std::cout << "The stack is a region of memory that handles static memory allocation." << std::endl;
    std::cout << "Heap memory handles dynamic memory allocation, allowing memory to be allocated and deallocated at runtime." << std::endl;
    std::cout << "Source: https://medium.com/@vinodh_36508/understanding-memory-allocation-in-swift-stack-vs-heap-03682b528bff" << std::endl;

    // 2. Dangling pointer
    std::cout << "Dangling pointers are pointers that are pointing to a memory location that has been already freed or deleted." << std::endl;
    std::cout << "Source: https://www.codewithharry.com/tutorial/c-dangling-pointer" << std::endl;

    // 3. Memory leak
    std::cout << "A memory leak is an unintentional form of memory consumption whereby the developer fails to free an allocated block of memory when no longer needed." << std::endl;
    std::cout << "Source: https://owasp.org/www-community/vulnerabilities/Memory_leak" << std::endl;

    // 4. Why are data structures like std::vector or std::string preferred

    return EXIT_SUCCESS;
}
*/

// In the worst case scenario the algorithm needs to check N-1 elements
// On average the algorithm needs to check N/2 elements during a linear search
int linearSearch(int* array, int arraySize, int searchValue) {
    std::cout << "Initiating linear search for value " << searchValue << std::endl;

    for (int i = 0; i < arraySize; i++) {
        std::cout << "Index: " << i << " | Value: " << array[i] << std::endl;
        if (array[i] == searchValue) {
            std::cout << "Value found at " << i << std::endl;
            return array[i];
        }
    }

    std::cout << "Value not found" << std::endl;
    return -1;
}

int binarySearch(int* array, int arraySize, int searchValue) {
    std::cout << "Initiating binary search for value " << searchValue << std::endl;

    int start = 0;
    int end = arraySize - 1;
    int mid = 0;

    while (start != end) {
        mid = (start + end) / 2;
        std::cout << "Index: " << mid << " | Value: " << array[mid] << std::endl;
        if (array[mid] == searchValue) {
            std::cout << "Value found at " << mid << std::endl;
            return mid;
        }

        if (array[mid] > searchValue) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    if (array[start] == searchValue && array[end] == searchValue) {
        std::cout << "Value found at " << start << std::endl;
        return start;
    }
    else {
        std::cout << "Value.. not found?" << std::endl;
        return -1;
    }
}

int finalTest() {
    auto start = std::chrono::steady_clock::now();

    const int repeatTimes = 100000000000000000;

    const int bigSize = 100000;
    const int biggerSize = 1000000;
    const int biggestSize = 10000000;

    int* a = new int[bigSize];
    int* b = new int[biggerSize];
    int* c = new int[biggestSize];

    for (int i = 0; i < bigSize; i++) {
        a[i] = i;
    }

    for (int i = 0; i < biggerSize; i++) {
        b[i] = i;
    }

    for (int i = 0; i < biggestSize; i++) {
        c[i] = i;
    }

    std::cout << "Final tests | Big size:" << std::endl;
    for (int i = 0; i < repeatTimes; i++) {
        linearSearch(a, bigSize, rand() % (bigSize + 1));
        std::cout << std::endl;
        binarySearch(a, bigSize, rand() % (bigSize + 1));
        std::cout << std::endl;
    }

    std::cout << "Final tests | Bigger size:" << std::endl;
    for (int i = 0; i < repeatTimes; i++) {
        linearSearch(b, biggerSize, rand() % (biggerSize + 1));
        std::cout << std::endl;
        binarySearch(b, biggerSize, rand() % (biggerSize + 1));
        std::cout << std::endl;
    }

    std::cout << "Final tests | Biggest size:" << std::endl;
    for (int i = 0; i < repeatTimes; i++) {
        linearSearch(c, biggestSize, rand() % (biggestSize + 1));
        std::cout << std::endl;
        binarySearch(c, biggestSize, rand() % (biggestSize + 1));
        std::cout << std::endl;
    }

    auto end = std::chrono::steady_clock::now();

    std::cout << "Final tests took " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " seconds" << std::endl;

    return 0;
}
// Performing the searches takes less than 1 second when run 20 times
// Performing the searches takes 14 seconds when run 100000 times
// Performing the searches is estimated to take 14000000000000 seconds (443642 years, 4 months, 2 days, 53 minutes and 20 seconds) when run 100000000000000000 times
// The 100000000000000000 searches were interrupted

int main() {
    const int size = 20;

    int a[size] = { 1, 4, 6, 11, 13, 16, 19, 20, 25, 27, 29, 30, 32, 36, 39, 42, 45, 48, 49, 53 };

    //for (int i = 0; i < size; i++) {
    //    a[i] = i;
    //}

    linearSearch(a, size, 11);
    std::cout << std::endl;

    binarySearch(a, size, 39);
    std::cout << std::endl;
    binarySearch(a, size, 15);
    std::cout << std::endl;
    //finalTest();
}