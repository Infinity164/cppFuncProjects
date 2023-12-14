#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    const int num = 100;
    int array1[num] = {};
    int array2[num] = {};
    int array3[num] = {};
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    bool flag = true;


    for (int i = 0; i < num; i++) {
        array1[i] = 1 + rand() % 99;
        array2[i] = array1[i];
        array3[i] = array1[i];
        cout << array1[i] << " ";
    }
    cout << endl;
    cout << "Идет вычисление.";
    cout << endl;
    Sleep(1000);


    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num-1-i; j++) {
            count1++;
            if (array1[j] > array1[j + 1]) {             
                swap(array1[j], array1[j + 1]);
                flag = false;
            }
           
        }
        if (flag) break;
    }
    cout << count1 << " - " << "array1 (bubble sort)";
    cout << endl;
    cout << "Идет вычисление.";
    cout << endl;
    Sleep(1000);


    for (int i = 0; i < num; i++) {
        for (int j = i; j > 0; j--) {
            count2++;
            if (array2[j] < array2[j - 1]) {
                
                swap(array2[j], array2[j - 1]);
            }
            else break;
        }
    }
    cout << count2 << " - " << "array2 (insertion sort)";
    cout << endl;
    cout << "Идет вычисление.";
    cout << endl;
    Sleep(1000);


    for (int a = 0, b = num, flag; a < b; ) {
        flag = true;
        for (int j = a; j < b - 1; j++) {
            count3++;
            if (array3[j] > array3[j + 1]) {
                
                swap(array3[j], array3[j + 1]);
                flag = false;
            }
        }
        if (flag) break;
        b--;
        flag = 1;
        for (int j = b - 1; j > a; j--) {
            count3++;
            if (array3[j] < array3[j - 1]) {
                
                swap(array3[j], array3[j - 1]);
                flag = false;
            }
        }
        if (flag) break;
        a++;
    }
    cout << count3 << " - " << "array3 (shaker sort)";
}