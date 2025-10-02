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

    std::cout << "Sorting took ~" << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << " nanoseconds" << std::endl;
    // 300000 values is already a stack overflow
    // Sorting took ~37200 nanoseconds for 100 values
    // Sorting took ~1986900 nanoseconds for 1000 values -> 0.002 seconds
    // Sorting took ~144075300 nanoseconds for 10000 values -> 0.14 seconds
    // Sorting took ~12979807300 nanoseconds for 100000 values -> 12.3 seconds

    // The function does not follow the O(f(n)) that was found
    // Swapping values between each other takes its own time
    // Thus the sorting time grows at an inconsistent pace.
}

int main() {
    const int size = 100000;
    float testArray[size];

    for (int i = 0; i < size; i++) {
        testArray[i] = rand() % (size + 1);
    }

    simpleSort(testArray, size);

    /*for (int i = 0; i < size; i++) {
        std::cout << testArray[i] << std::endl;
    }*/
}