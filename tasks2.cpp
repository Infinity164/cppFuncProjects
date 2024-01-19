

#include <iostream>
using namespace std;

void showArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i];
    }
}

void sort(int array[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size-1-i; j++) {
            if (array[j] > array[j+1]) 
                swap(array[j], array[j+1]);
           
        }
    }
}

int sumofarrays(int array[], int array2[], int size, int size2) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    for (int j = 0; j < size2; j++) {
        sum += array2[j];
    }
    return sum;
}

void reversearray(int array[], int size) {
    for (int i = 0; i < size/2; i++) {
        swap(array[i], array[size-1-i]);
    }
}

void sortingByArrays(int array1[], int array2[], int array3[], int size) {
    for (int i = 0; i < size; i++) {
        swap(array3[array1[i]], array3[array2[i]]);
    }
}

int main()
{
    int array1[] = { 1, 3, 5 };
    int array2[] = { 2, 4, 2 };
    int array3[] = { 1, 2, 3, 4, 5, 6 };
    int size = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array3) / sizeof(array3[0]);
    showArray(array3, size2);
    cout << endl;
    sortingByArrays(array1, array2, array3, size);
    showArray(array3, size2);

}
