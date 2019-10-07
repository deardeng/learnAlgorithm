#ifndef __MERGE_SORT_H_
#define __MERGE_SORT_H_
#include "SortTestHelper.h"

using namespace std;

// 将arr[l...mid]和arr[mid+1...r]两部分进行归并
template <typename T>
void __merge(T arr[], int l, int mid, int r){
    T aux[r-l+1];
    for(int i =l; i <=r; i++){
        aux[i-l] = arr[i];
    }

    int i = l, j = mid+1;
    for(int k = l; k <= r; k++){
        if(i > mid){
            arr[k] = aux[j-l];
            j++;
        }else if(j > r) {
            arr[k] = aux[i - l];
            i++;
        }else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template <typename T>
void __mergeSort(T arr[], int l, int r){
    if(l >= r)
        return;
    int mid = (l + r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    __merge(arr, l, mid, r);
}

// 对arr[l...r]范围的数组进行插入排序
template <typename T>
void insertionSort(T arr[], int l, int r){
    for(int i = l+1; i <= r; i++){
        T e = arr[i];
        int j;
        for(j = i; j > l && arr[j-1] > e; j--)
            arr[j] = arr[j-1];
        arr[j] = e;
    }
    return;
}

// 递归使用归并排序，对arr[l...r]的范围进行排序
template <typename T>
void __mergeSortOptimize(T arr[], int l, int r){
//    if(l >= r)
//        return;

    if (r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }

    int mid = (l + r)/2;
    __mergeSort(arr, l, mid);
    __mergeSort(arr, mid+1, r);
    if(arr[mid] > arr[mid+1]){
        __merge(arr, l, mid, r);
    }
}

template<typename T>
void mergeSort(T arr[], int n){
    __mergeSort(arr, 0, n-1);
}


template<typename T>
void mergeSortOptimize(T arr[], int n){
    __mergeSortOptimize(arr, 0, n-1);
}

#endif
