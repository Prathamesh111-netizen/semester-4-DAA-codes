#include <bits/stdc++.h>
using namespace std;

void SelectionSort(vector<int> &arr){
    int n = arr.size();

    for (int i = 0; i < n - 1; i++){
        int mini = i;
        for (int j = i; j < n; j++)
            if (arr[j] < arr[mini])
                mini = j;
        
        swap(arr[mini], arr[i]);
    }

}

int main(){
    vector<int> arr = {4, 5, 2, 5, 6, 1};
    SelectionSort(arr);
    for (auto x : arr)
        cout << x << " ";
}