#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void QuickSort(vector<int> arr, int l , int r){
    while (r > l){
        int pi = partition(arr, l, r);
        QuickSort(arr, l , pi - 1);
        QuickSort(arr, pi + 1, r);
    }
}