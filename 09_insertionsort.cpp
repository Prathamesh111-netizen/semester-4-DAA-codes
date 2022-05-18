#include <bits/stdc++.h>
using namespace std;

void InsertionSort(vector<int> &arr){
    int n = arr.size();

    for (int i = 1; i < n; i++){
        int j = i - 1;
        int num = arr[i];

        while ( j >= 0 && num < arr[j]){
            swap(arr[j], arr[j + 1]);
            j--;
        }
        swap(num, arr[j + 1]);
    }

}

int main(){
    vector<int> arr = {4, 5, 2, 5, 6, 1};
    InsertionSort(arr);
    for (auto x : arr)
        cout << x << " ";
}