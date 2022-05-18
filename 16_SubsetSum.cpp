#include <bits/stdc++.h>
using namespace std;
// contingous subarray only
set<vector<int>> answer;
vector<int> temp;
vector<int> arr;
int target;
int nodes;

void subsetsumCalc(int sum, int i)
{
    nodes++;
    if (i == arr.size() || sum >= target)
    {
        if (sum == target)
            answer.insert(temp);
    
        return;
    }
    temp.push_back(arr[i]);
    subsetsumCalc(sum + arr[i], i + 1);
    temp.clear();
    subsetsumCalc(0, i + 1);
}

set<vector<int>> SubsetSum(vector<int> &candidates, int t)
{
    arr.clear(), temp.clear(), answer.clear();
    arr = candidates;
    target = t;
    nodes = 0;
    subsetsumCalc(0, 0);
    return answer;
}

int main()
{
    int n;
    cout << "Array Size : "; cin >> n;

    cout << "Enter Array Elements :";
    vector<int> candidates(n);
    for (int i = 0; i < n; i++)
        cin >> candidates[i];

    int t;
    cout << "Enter the Target Sum : ";
    cin >> t;

    set<vector<int>> answer = SubsetSum(candidates, t);
    cout << "No of nodes : " << nodes << endl << endl;
    cout << "Answer tuples : " << endl;
    for (auto x : answer)
    {
        for (auto y : x)
            cout << y << " ";
        cout << endl;
    }
    return 0;
}