#include <iostream>
#include <iomanip>

int fib_recursive(int n) {
	if (n <= 1) {
		return 1;
	}
	return fib_recursive(n - 1) + fib_recursive(n - 2);
}

int main() {
	int n = 7;

	long long fib = fib_recursive(n);

	std::cout << "Fibonacci number f(" << n << ") = " << fib << std::endl;
	return EXIT_SUCCESS;
}