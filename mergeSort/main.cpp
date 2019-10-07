#include <iostream>
#include "SortTestHelper.h"
#include "Student.h"
#include "mergeSort.h"

using namespace std;

template <typename T>
void mergeSortBU(T arr[], int n){
    for(int sz=1; sz <= n; sz += sz){
        for(int i = 0; i + sz < n; i += sz + sz){
            //对 arr[i...i+sz-1] 和 arr[i+sz ... i+2*sz-1] 进行归并
            __merge(arr, i, i+sz -1, min(i+sz + sz -1, n-1));
        }
    }
}


int main() {
//
    int n = 50000;
    cout << "Test for random array, size=" << n << ", random range [0, " << n << "]" << endl;
    int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
//    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
//
    SortTestHelper::testSort("merge sort bu", mergeSortBU, arr1, n);
//
    delete[] arr1;
//    delete[] arr2;
//
//    int swapTimes = 10;
//    cout << "Test for Random Nearly Ordered Array, size = " << n << ", swap time = " << swapTimes << endl;
//    arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
//
//    SortTestHelper::testSort("Merge sort", mergeSortOptimize, arr1, n);
//
//    delete[] arr1;
    return 0;
}