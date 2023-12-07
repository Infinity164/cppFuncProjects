

#include <iostream>
using namespace std;

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");

    const int num = 10;
    int enda;
    int summ = 0;
    int minIndex = 0;
    int maxIndex = 0;
    cin >> enda;
    int array[num] = {};
    for (int i = 0; i < num; i++) {
        array[i] = 1 + rand() % enda;
        cout << array[i] << " ";
    }
    int max = array[0];
    int min = array[0];
    for (int i = 0; i < num; i++) {
        if (max < array[i]) {
            max = array[i];
            maxIndex = i;
        }
        if (min > array[i]) {
            min = array[i];
            minIndex = i;
        }
    }
    cout << endl << min << " " << minIndex;
    cout << endl << max << " " << maxIndex;
}

