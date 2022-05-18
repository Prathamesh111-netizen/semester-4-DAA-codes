#include <bits/stdc++.h>
using namespace std;

bool BinarySearch(vector<int> arr, int target){
    int n = arr.size();

    int l = 0;
    int r = n - 1;

    while ( l < r){
        int mid = l + (r - l)/2;
        if (arr[mid] == target) 
            return true;
        
        if (arr[mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

int main(){
    return 0;
}