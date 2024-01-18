

#include <iostream>
using namespace std;

void task1(float n, float k) {
    for (int i = 0; i < n; i++) {
        cout << "*";
        for (int j = 0; j < k-1; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int task2(int x) {
    int m = 1;
    for (int i = 1; i <= x; i++) {
        m *= i;
    }
    return m;
}

bool task3(int x) {
    bool flag = true;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            flag = false;
            break;
        }
    }
    return flag;
}

int task4(int x) {
    return x = pow(x, 3);
}

void task5(float x, float y) {
    if (x > y) cout << x;
    else cout << y;
}

bool task6(float x) {
    if (x > 0) return true;
    else return false;
}

int task1_1(int x, int y) {
    int m;
    for (int i = 0; i <= y; i++) {
        m = x*x;
    }
    return m;
}

int task2_2(int x, int y) {
    if (x > y) swap(x, y);
    int m = 0;
    for (int i = x+1; i < y ; i++) {
        m += i;
    }
    return m;
}


bool absolute(int x) {
    int count = 0;
    for (int i = 1; i < x; i++) {
        if (x % i == 0) count += i;
    }
    if (x == count) return true;
    else return false;
}
void task3_3(int x, int y) {
    for (int i = x; i <= y; i++) {
        if (absolute(i)) cout << i;
    }
}



int main()
{
    task3_3(1, 22);
}


