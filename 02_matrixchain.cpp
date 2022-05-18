#include <bits/stdc++.h>
using namespace std;


int matrixChain(vector<int> d){
    int n = d.size() - 1;
    cout << n << endl;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, INT_MAX));

    for (int i = 1; i <= n; i++)    
        matrix[i][i] = 0;

    for (int x = 2; x <= n; x++)
        for (int i = 1, j = x; i <= n && j <= n;i++, j++)
            for (int k = i; k < j; k++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k + 1][j] + d[i - 1] * d[k] * d[j]);

    for (int i = 1; i < matrix.size(); i++, cout << endl)
        for (int j = 1; j < matrix[i].size(); j++)
            cout  << setw(10) << matrix[i][j] << " ";
    

    return matrix[1][n];
}

int main(){
    int n; cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];

    cout << matrixChain(d) << endl;
    return 0;
}