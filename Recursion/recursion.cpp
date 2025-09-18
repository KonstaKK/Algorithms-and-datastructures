#include <iostream>
#include <iomanip>

int fib_recursive(int n) {
	if (n <= 1) {
		return 1;
	}
	return fib_recursive(n - 1) + fib_recursive(n - 2);
}

long long fib_iter_array(int n) {
	long long* array = new long long[n + 1];
	array[0] = 1;
	array[1] = 1;

	for (int i = 2; i < n + 1; i++) {
		array[i] = array[i - 1] + array[i - 2];
		//std::cout << "array index " << i << " is " << array[i] << std::endl;
	}

	long long result = array[n];
	delete[] array;

	return result;
}

int main() {
	int n = 400;

	//long long fib = fib_recursive(n);

	std::cout << "Fibonacci number f(" << n << ") = " << fib_iter_array(n) << std::endl;

	return EXIT_SUCCESS;
}