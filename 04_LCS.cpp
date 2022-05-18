#include <bits/stdc++.h>
using namespace std;

int LCS(string a, string b){
    int n = a.size(), m = b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if ( a[i - 1] == b[ j - 1])
                dp[i][j] = dp[i - 1][ j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    
    for (int i = 0; i <= n; i++, cout << endl)
        for (int j = 0; j <= m; j++)
            cout << setw(2) << dp[i][j] << " ";
    
    return dp[n][m];
}
int main(){
    string a, b;
    cin >> a >> b;

    cout << LCS(a, b) << endl;
    return 0;
}