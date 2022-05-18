#include <bits/stdc++.h>
using namespace std;

// greedy
int greedy_Knapsack(vector<double>profit, vector<double>weight, int capacity ){
    int n = profit.size();
    int answer = 0;

    priority_queue<pair<int,int>> minpq;
    for (int i = 0; i < n; i++)
        minpq.push(make_pair(profit[i] / weight[i], i));

    while (capacity > 0 && minpq.empty() == false){
        auto itr = minpq.top();
        minpq.pop();

        cout << itr.first << " " << itr.second << endl;

        if (weight[itr.second] <= capacity)
            capacity -= weight[itr.second],
            answer += profit[itr.second];
    }

    return answer;    
}
// DP

// backtracking

// branch and bound


int main(){
    int n; cin >> n;
    int capacity; cin >> capacity;
    vector<double>profit(n), weight(n);
    for (int i = 0; i < n; i++)
        cin >> profit[i];
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cout << greedy_Knapsack(profit, weight, capacity) << endl; 

    return 0;
}