// Material has code
// Look Shell sort / Merge sort up from the internet
// Use your own imagination
// Use std::sort()
// Test that the sorts work

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

void ShellSort(float* a, int n) {
	int i, j, gap;
	float tmp;
	for (gap = n / 2; gap > 0; gap /= 2) {
		for (i = gap; i < n; ++i) {
			tmp = a[i];
			for (j = i; j >= gap && tmp < a[j - gap]; j -= gap) {
				a[j] = a[j - gap];
			}
			a[j] = tmp;
		}
	}

}

// source: https://www.programiz.com/dsa/merge-sort
void Merge(float* a, int left, int m, int right) {
	int n1 = m - left + 1;
	int n2 = right - m;

	std::vector<int> L(n1);
	std::vector<int> M(n2);

	for (int i = 0; i < n1; i++)
		L[i] = a[left + i];

	for (int j = 0; j < n2; j++)
		M[j] = a[m + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= M[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = M[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		a[k] = M[j];
		j++;
		k++;
	}
}
void MergeSort(float* a, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}

void STDSort(float* array, bool display) {
	std::vector<float> temp;

	for (int i = 5; i >= 0; i--) {
		temp.push_back(array[i]);
	}

	std::sort(temp.begin(), temp.end());

	if (display) {
		std::cout << "Sorted with std: [";
		for (int i = 0; i < 5; i++)
		{
			std::cout << temp[i] << ", ";
		}
		std::cout << temp[5] << "]" << std::endl;
	}
}

int main() {
	// 9.1.
	float shell[6] = {9, 2, 6, 5, 7, 1};
	float merge[6] = {9, 2, 6, 5, 7, 1};
	float stdArray[6] = {9, 2, 6, 5, 7, 1};

	std::cout << "array: [";
	for (int i = 0; i < 5; i++)
	{
		std::cout << shell[i] << ", ";
	}
	std::cout << shell[5] << "]" << std::endl;
	std::cout << std::endl;

	ShellSort(shell, 6);
	std::cout << "Sorted with shell: [";
	for (int i = 0; i < 5; i++)
	{
		std::cout << shell[i] << ", ";
	}
	std::cout << shell[5] << "]" << std::endl;

	MergeSort(merge, 0, 5);
	std::cout << "Sorted with merge: [";
	for (int i = 0; i < 5; i++)
	{
		std::cout << merge[i] << ", ";
	}
	std::cout << merge[5] << "]" << std::endl;

	STDSort(stdArray, true);
	/*std::cout << "Sorted with std: [";
	for (int i = 0; i < 5; i++)
	{
		std::cout << stdArray[i] << ", ";
	}
	std::cout << stdArray[5] << "]" << std::endl;*/
	std::cout << std::endl;

	// 9.2.
	float smallOrdered[10];
	float smallReverse[10];
	float smallRandom[10];
	float mediumOrdered[100];
	float mediumReverse[100];
	float mediumRandom[100];
	float largeOrdered[1000];
	float largeReverse[1000];
	float largeRandom[1000];

	float smallOrdered2[10];
	float smallReverse2[10];
	float smallRandom2[10];
	float mediumOrdered2[100];
	float mediumReverse2[100];
	float mediumRandom2[100];
	float largeOrdered2[1000];
	float largeReverse2[1000];
	float largeRandom2[1000];

	float smallOrdered3[10];
	float smallReverse3[10];
	float smallRandom3[10];
	float mediumOrdered3[100];
	float mediumReverse3[100];
	float mediumRandom3[100];
	float largeOrdered3[1000];
	float largeReverse3[1000];
	float largeRandom3[1000];

	for (int i = 0; i < 10; i++) {
		smallOrdered[i] = i;
		smallReverse[i] = 10 - i;
		smallRandom[i] = rand() % 10;
		smallOrdered2[i] = smallOrdered[i];
		smallOrdered3[i] = smallOrdered[i];
		smallReverse2[i] = smallReverse[i];
		smallReverse3[i] = smallReverse[i];
		smallRandom2[i] = smallRandom[i];
		smallRandom3[i] = smallRandom[i];
	}

	for (int i = 0; i < 100; i++) {
		mediumOrdered[i] = i;
		mediumReverse[i] = 100 - i;
		mediumRandom[i] = rand() % 100;
		mediumOrdered2[i] = mediumOrdered[i];
		mediumOrdered3[i] = mediumOrdered[i];
		mediumReverse2[i] = mediumReverse[i];
		mediumReverse3[i] = mediumReverse[i];
		mediumRandom2[i] = mediumRandom[i];
		mediumRandom3[i] = mediumRandom[i];
	}

	for (int i = 0; i < 1000; i++) {
		largeOrdered[i] = i;
		largeReverse[i] = 1000 - i;
		largeRandom[i] = rand() % 1000;
		largeOrdered2[i] = largeOrdered[i];
		largeOrdered3[i] = largeOrdered[i];
		largeReverse2[i] = largeReverse[i];
		largeReverse3[i] = largeReverse[i];
		largeRandom2[i] = largeRandom[i];
		largeRandom3[i] = largeRandom[i];
	}

	std::cout << std::endl;
	std::cout << "Already sorted 10 element array, shell sort, starting" << std::endl;
	auto start1 = std::chrono::steady_clock::now();
	ShellSort(smallOrdered, 10);
	auto end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Already sorted 10 element array, merge sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	MergeSort(smallOrdered2, 0, 9);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Already sorted 10 element array, std sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	STDSort(smallOrdered3, false);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Already sorted 100 element array, shell sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	ShellSort(mediumOrdered, 100);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Already sorted 100 element array, merge sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	MergeSort(mediumOrdered2, 0, 99);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Already sorted 100 element array, std sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	STDSort(mediumOrdered3, false);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Already sorted 1000 element array, shell sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	ShellSort(largeOrdered, 1000);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Already sorted 1000 element array, merge sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	MergeSort(largeOrdered2, 0, 999);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Already sorted 1000 element array, std sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	STDSort(largeOrdered3, false);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Reversed 10 element array, shell sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	ShellSort(smallReverse, 10);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Reversed 10 element array, merge sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	MergeSort(smallReverse2, 0, 9);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Reversed 10 element array, std sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	STDSort(smallReverse3, false);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Reversed 100 element array, shell sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	ShellSort(mediumReverse, 100);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Reversed 100 element array, merge sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	MergeSort(mediumReverse2, 0, 99);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Reversed 100 element array, std sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	STDSort(mediumReverse3, false);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Reversed 1000 element array, shell sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	ShellSort(largeReverse, 1000);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Reversed 1000 element array, merge sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	MergeSort(largeReverse2, 0, 999);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Reversed 1000 element array, std sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	STDSort(largeReverse3, false);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Randomized 10 element array, shell sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	ShellSort(smallRandom, 10);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Randomized 10 element array, merge sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	MergeSort(smallRandom2, 0, 9);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Randomized 10 element array, std sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	STDSort(smallRandom3, false);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Randomized 100 element array, shell sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	ShellSort(mediumRandom, 100);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Randomized 100 element array, merge sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	MergeSort(mediumRandom2, 0, 99);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Randomized 100 element array, std sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	STDSort(mediumRandom3, false);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Randomized 1000 element array, shell sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	ShellSort(largeReverse, 1000);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Randomized 1000 element array, merge sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	MergeSort(largeRandom2, 0, 999);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;

	std::cout << std::endl;
	std::cout << "Randomized 1000 element array, std sort, starting" << std::endl;
	start1 = std::chrono::steady_clock::now();
	STDSort(largeRandom3, false);
	end1 = std::chrono::steady_clock::now();
	std::cout << "Time: ~" << std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1).count() << " microseconds" << std::endl;
}