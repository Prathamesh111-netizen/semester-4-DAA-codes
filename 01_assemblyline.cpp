#include <bits/stdc++.h>
using namespace std;

void write(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int AssemblyLineScheduling(vector<int> &a, vector<int> &b, vector<int> &l, vector<int> &r)
{
    int n = a.size();
    vector<vector<int>> answer(2, vector<int>(n, 0));
    vector<vector<int>> path(2, vector<int>(n, 0));

    answer[0][0] = a[0],answer[1][0] = b[0];
    path[0][0] = 1, path[1][0] = 2;

    for (int i = 1; i < n; i++)
    {
        if (answer[0][i - 1] + a[i] <  answer[1][i - 1] + a[i] + r[i - 1])
            answer[0][i] = answer[0][i - 1] + a[i],
            path[0][i] = 1;
        else
            answer[0][i] = answer[1][i - 1] + a[i] + r[i - 1],
            path[0][i] = 2;

        if (answer[1][i - 1] + b[i] < answer[0][i - 1] + b[i] + l[i - 1])
            answer[1][i] = answer[1][i - 1] + b[i],
            path[1][i] = 2;
        else
            answer[1][i] = answer[0][i - 1] + b[i] + l[i - 1],
            path[1][i] = 1;
    }

    

    return min(answer[0][n - 1], answer[1][n - 1]);
}

int main()
{

    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];



    return 0;
}