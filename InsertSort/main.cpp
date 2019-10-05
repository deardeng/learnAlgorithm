#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n) {
    for(int i = 1; i < n; i++){
        // 寻找元素arr[i]合适的插入位置
        for(int j = i; j > 0; j --){
            if(arr[j] < arr[j-1])
                swap(arr[j], arr[j-1]);
            else
                break;
        }
    }
}

template <typename T>
void insertionSortOptimize(T arr[], int n){
    for (int i = 1; i < n; i++){
        // 寻找元素arr[i]合适的插入位置
        T e = arr[i];
        int j; // j保存元素e应该插入的位置
        for( j = i; j > 0 && arr[j-1] > e; j--){
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

int main() {
    int n = 10000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    int *arr3 = SortTestHelper::generateNearlyOrderedArray(n, 100);
    SortTestHelper::testSort("insertion sort", insertionSort, arr, n);
    SortTestHelper::printArray(arr,n);
    SortTestHelper::testSort("insertion optimize sort", insertionSortOptimize, arr2, n);
    SortTestHelper::testSort("insertion optimize sort", insertionSortOptimize, arr3, n);


    delete[] arr;
    delete[] arr2;
    return 0;
}