#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans;
    vector<int>pos;

    bool isSafe(int k, int j){

        // kth row, jth column
        for (int i = 0; i < k; i++){
            if (pos[i] == j || pos[i] + i == j + k || pos[i] - i == j - k)
                return false;
        }
        return true;
    }

    void Nqueens(int n, int k){
        if (k == n){
            ans++;
            return;
        }

        for (int i = 0; i < n; i++){
            if(isSafe(k , i)){
                pos[k] = i;
                Nqueens(n, k + 1);
                pos[k] = -1;
            }
        }

    }
    int totalNQueens(int n) {
        ans = 0;
        pos.clear();
        pos.resize(n, -1);
        Nqueens(n, 0);
        return ans;
    }
};

int main(){
    return 0;
}