#include <bits/stdc++.h>
using namespace std;

// DSU
vector<int> parent, rankf;

void make_set(int v){
    parent[v] = v;
    rankf[v] = 0;
}

int find_set(int v){
    if (parent[v] == v)
        return v;
    
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if ( a != b ){
        if (rankf[a] < rankf[b])
            swap(a, b);
        
        parent[b] = a;
        if (rankf[a] == rankf[b])
            rankf[a]++;
    }
}


void kruskal(vector<vector<pair<int,int>>> adj){
    // sort edges according to weight
    int n = adj.size();
    parent.resize(n, -1);
    rankf.resize(n, -1);

    vector<pair<int, pair<int,int>>> edges;
    for (int i = 0; i < n; i++)
        for (auto x : adj[i])
            edges.push_back(make_pair(x.second, make_pair(i, x.first)));
    
    sort(edges.begin(), edges.end());
    // sort(edges.begin(), edges.end(), [](
    //     const pair<int,pair<int,int>>a, const pair<int,pair<int,int>>b) {
    //         return a.first > b.first;
    // });

    int cost = 0;
    vector<pair<int,int>> answer;

    for (auto x : edges){
        int u = x.second.first,
            v = x.second.second;

        if (find_set(u) != find_set(v)){
            cost += x.first;
            answer.push_back({u, v});
            union_sets(u, v);
        }
    }






}

int main(){
    return 0;
}