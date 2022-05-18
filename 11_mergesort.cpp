#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> arr, int l, int r, int mid){
    
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> left(n1), right(n2);
    
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = l;
    while ( i < n1 && j < n2){
        if (left[i] < right[j]){
            arr[k] = left[i];
            k++;
            i++;
        }
        else{
            arr[k] = right[j];
            k++;
            j++;
        }
    }

    while ( i < n1){
        arr[k] = left[i];
        k++;
        i++;
    }

    while ( j < n2){
        arr[k] = right[j];
        k++;
        j++;
    }

}

void mergeSort(vector<int> arr, int l , int r){
    int l = 0, r = arr.size() - 1;
    while ( r > l){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l , r, mid);
    }
}   