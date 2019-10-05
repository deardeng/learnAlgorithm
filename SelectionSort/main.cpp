#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        // 寻找[i,n)区间里的最小值
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    delete[] arr;

    Student d[4] = {{"D", 90},
                    {"C", 100},
                    {"B", 95},
                    {"A", 99}
    };

    for (int i = 0; i < 4; i++){
        cout << d[i];
    }
    cout << endl;
    selectionSort(d, 4);
    for (int i = 0; i < 4; i++)
        cout << d[i];
    cout << endl;

    return 0;
}