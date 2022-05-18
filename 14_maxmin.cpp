#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

void MaxMin(int x, int y){
    if y – x ≤ 1 then
    return (max(numbers[x], numbers[y]), min((numbers[x], numbers[y]))
    else
    (max1, min1):= maxmin(x, ⌊((x + y)/2)⌋)
    (max2, min2):= maxmin(⌊((x + y)/2) + 1)⌋,y)
    return (max(max1, max2), min(min1, min2))
}

int main(){
    return 0;
}