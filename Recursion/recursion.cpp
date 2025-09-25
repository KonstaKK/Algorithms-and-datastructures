#include <iostream>
#include <iomanip>

// Programming task 3.1.	first solution
long long fib_iter_array(int n) {
	long long* array = new long long[n + 1];
	array[0] = 1;
	array[1] = 1;

	for (int i = 2; i < n + 1; i++) {
		array[i] = array[i - 1] + array[i - 2];
		std::cout << "array index " << i << " is " << array[i] << std::endl;
	}

	long long result = array[n];
	delete[] array;

	return result;
}

// Programming task 3.1.	optimized solution
int fib_recursive(int n) {
	if (n <= 1) {
		return 1;
	}
	return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Programming task 3.2.
int ackerman_function(int m, int n) {
	std::cout << "A(" << m << ", " << n << ")";

	if (m == 0 && n > 0) {
		std::cout << " = " << (n + 1) << std::endl;
		return (n + 1);
	}
	else if (m > 0 && n == 0) {
		std::cout << " = A(" << (m - 1) << ", " << 1 << ")" << std::endl;
		ackerman_function((m - 1), 1);
	}
	else if (m > 0 && n > 0) {
		std::cout << " = A(" << (m - 1) << ", A(" << m << ", " << (n - 1) << "))" << std::endl;
		ackerman_function((m - 1), ackerman_function(m, (n - 1)));
	}
}

int main() {
	int x = 8;

	//long long fib = fib_recursive(n);

	std::cout << "Fibonacci number f(" << x << ") = " << fib_iter_array(x) << std::endl;
	std::cout << std::endl;

	std::cout << "Fibonacci number f(" << x << ") = " << fib_recursive(x) << std::endl;
	std::cout << std::endl;

	int m = 2;
	int n = 2;

	std::cout << "Ackermann function f(2, 2) = " << ackerman_function(m, n) << std::endl;

	/*int max = 2000;
	for (m = 2; m <= max; m++) {
		for (n = 2; n <= max; n++) {
			std::cout << "Ackermann function f(" << m << ", " << n << ") = " << ackerman_function(m, n) << std::endl;
		}
	}*/
	// The highest reasonable value for m is 3
	// When m is 2, the highest value for n is ~2000
	// When m is 3, the highest value for n is 8

	return EXIT_SUCCESS;
}