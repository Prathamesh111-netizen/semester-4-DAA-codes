#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int,int>>>adj){
    int n = adj.size();

    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);

    int source = 0;
    distance[source] = 0;

    set<pair<int,int>> minpq;
    minpq.insert(make_pair(0, source));

    while (minpq.empty() == false){
        int u = minpq.begin()->second;
        minpq.erase(minpq.begin());

        for (auto x : adj[u]){
            int v = x.first;
            int w = x.second;

            if (distance[v] > distance[u] + w){
                minpq.erase(make_pair(distance[v], v));
                distance[v] = distance[u] + w;
                parent[v] = w;
                minpq.insert(make_pair(distance[v], v));
            }
        }
    }
}

int main(){
    return 0;
}