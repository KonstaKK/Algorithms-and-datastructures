#include <iostream>
#include <iomanip>
#include <chrono>

void swap(float& a, float& b) {
    float c(a); a = b; b = c;
}

void simpleSort(float* a, int n) {
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[j] < a[i]) {
                //std::cout << "Before: " << a[j] << " " << a[i] << std::endl;
                swap(a[j], a[i]);
                //std::cout << "After: " << a[j] << " " << a[i] << std::endl;
            }
        }
    }
    auto end = std::chrono::steady_clock::now();

    std::cout << "Sorting took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " milliseconds" << std::endl;
    // 300000 values is already a stack overflow
    // ~0.139 seconds for 10000 values
    // ~12.993 seconds for 100000 values
    // ~50.537 seconds for 200000 values
}

int main() {
    const int size = 300000;
    float testArray[size];

    for (int i = 0; i < size; i++) {
        testArray[i] = rand() % (size + 1);
    }

    simpleSort(testArray, size);

    /*for (int i = 0; i < size; i++) {
        std::cout << testArray[i] << std::endl;
    }*/
}