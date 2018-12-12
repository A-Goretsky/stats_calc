#include "sorts.hpp"

//My old Java selectionSort translated into C++
void selectionSort(int a[], size_t size) {
	int minInd;
    int temp;
    for (int i = 0; i < size - 1; i++) {
        minInd = i;
        for (int x = i + 1; x < size; x++) {
            if (a[x] < a[minInd]) {
                minInd = x;
            }
        }
        temp = a[minInd];
        a[minInd] = a[i];
        a[i] = temp;
    }
}


//My old Java insertionSort translated into C++
void insertionSort(int a[], size_t size) {
	for (int part = 0; part < size; part++) {
		for (int x = part; x > 0; x--) {
			if (a[x] < a[x-1]) {
				std::swap(a[x], a[x-1]);
			}
			else {
				break;
			}
		}
	}
}

//My Old Java mergeSort. Not Yet translated.

