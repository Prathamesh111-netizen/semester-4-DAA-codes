#include <bits/stdc++.h>
using namespace std;

// DP
int Knapsack(vector<int> profit, vector<int> weight, int capacity){
    int n = profit.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));
    for (int i = 0; i <= n; i++)    
        dp[i][0] = 0;
    for (int i = 0; i <= capacity; i++)    
        dp[0][capacity] = 0;

    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= capacity; j++)
            if (weight[i - 1] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + profit[i - 1]);
            else    
                dp[i][j] = dp[i - 1][j];

    for (int i = 0; i <= n; i++, cout << endl)
        for (int j = 0; j <= capacity; j++)
            cout << setw(3) << dp[i][j] << " ";


    return dp[n][capacity];
}
// backtracking

// branch and bound


int main(){
    int n; cin >> n;
    int capacity; cin >> capacity;
    vector<int>profit(n), weight(n);
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << Knapsack(profit, weight, capacity) << endl; 

    return 0;
}