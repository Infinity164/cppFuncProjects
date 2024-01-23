#include <iostream>
using namespace std;

void showArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i];
	}
}

void showArray(int array[][3], int size, int size2) {
	for (int i = 0; i < size; i++) {
		showArray(array[i], size2);
		cout << endl;
	}
}

int countByIndex(int array[], int size, int num) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] == num) count++;
	}
	return count;
}

void deleteByIndex(int array[], int array2[], int size, int index) {
	for (int i = 0; i < index; i++) {
		array2[i] = array[i];
	}
	for (int j = index + 1; j < size; j++) {
		array2[j - 1] = array[j];
	}
}

void deleteByRange(int array[], int array2[], int size, int range1, int range2) {
	++range2;
	if (range1 > range2) swap(range1, range2);
	for (int i = 0; i < range1; i++) {
		array2[i] = array[i];
	}
	for (int i = range2, k = range1; i < size; i++, k++) {
		array2[k] = array[i];
	}
}

int maxElOfArray(int array[], int size) {
	int maxEl = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] > maxEl) maxEl = array[i];
	}
	return maxEl;
}

int maxElOfArray(int array[][3], int size, int size2) {
	int maxEl = 0;
	for (int i = 0; i < size; i++) {
		maxEl = maxElOfArray(array[i], size2);
	}
	return maxEl;
}

int summOfArray(int array[], int size) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		count += array[i];
	}
	return count;
}

int summOfArray(int array[][3], int size, int size2) {
	int count = 0;
	for (int i = 0; i < size; i++) {
		count += summOfArray(array[i], size2);
	}
	return count;
}

int main() {

	int array[] = { 2, 7, 1, 6, 0, 3 };
	int array2[] = { 1, 4, 5, 9, 2, 0 };
	int bigArray[3][3] = { {1,5,3},
						   {4,2,9},
						   {5,5,10} };
	int size = sizeof(array) / sizeof(array[0]);
	int bigSize = sizeof(bigArray) / sizeof(bigArray[0]);
 	int bigSize2 = sizeof(bigArray[0]) / sizeof(bigArray[0][0]);
	showArray(bigArray, bigSize, bigSize2);
	cout << endl;
	cout << summOfArray(bigArray, bigSize, bigSize2);
}