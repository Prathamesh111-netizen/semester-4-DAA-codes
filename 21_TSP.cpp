#include<bits/stdc++.h>

using namespace std;

void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
    #endif
}

void print(vector<vector<int>>adj){
    for (int i = 0; i < adj.size(); i++ , cerr << endl )
        for (int j = 0; j < adj.size(); j++)
            if (adj[i][j] != INT_MAX) cerr << setw(5) << adj[i][j] << " ";
            else cerr << setw(5) << "inf" << " ";

    cerr << "\n\n";
}


pair<int, vector<vector<int>>> row_reduction(vector<vector<int>>adj){

    int answer = 0;
    for (int i = 0; i < adj.size(); i++){

        int mini = INT_MAX;
        for (int j = 0; j < adj.size(); j++)
            mini = min(adj[i][j], mini);
        
        if ( mini == 0 || mini == INT_MAX)
            continue;
        else{
            answer += mini;
            for (int j = 0; j < adj.size(); j++)
                if (adj[i][j] != INT_MAX)
                    adj[i][j] -= mini;

        }
    }
    return make_pair(answer, adj);
}

pair<int, vector<vector<int>>> column_reduction(vector<vector<int>>adj){

    int answer = 0;
    for (int i = 0; i < adj.size(); i++){

        int mini = INT_MAX;
        for (int j = 0; j < adj.size(); j++)
            mini = min(adj[j][i], mini);
        
        if ( mini == 0 || mini == INT_MAX)
            continue;
        else{
            answer += mini;
            for (int j = 0; j < adj.size(); j++)
                if (adj[j][i] != INT_MAX)
                    adj[j][i] -= mini;
        }
    }
    return make_pair(answer, adj);
}

vector<vector<int>> make_infi(vector<vector<int>> adj, int _from, int _to, map<int,int>path){

    for (int i = 0; i < adj.size(); i++){
        adj[_from][i] = INT_MAX;
        adj[i][_to] = INT_MAX;
    }

    for (auto x : path)
        adj[_to][x.first] = INT_MAX;

    return adj;
}


map<int, int> tsp(vector<vector<int>>adj, long long &answer){
    int source = 0;
    map<int, int>path; path[source] = 0;
    int current_node = source;
    int pathLength = 1;

    // lower cost branch bound
    for (int i = 1; i < adj.size(); i++){
    // for (int i = 1; i < 2; i++){

        vector<int>rem;     // finding the remaining nodes on the path
        for (int j = 0; j < adj.size(); j++)
            if (path.find(j) == path.end())
                rem.push_back(j);

        map<long long,int>Cost;
        map<int, vector<vector<int>>>adjCopyStorage;
        cout << "Available Choices : \n";
        for (int j = 0; j < rem.size(); j++){
            auto _adjCopy = make_infi(adj, current_node, rem[j], path); // make infi
            // row reduction
            auto _row_reduction = row_reduction(_adjCopy);
            _adjCopy = _row_reduction.second;

            // column reduction
            auto _column_reduction = column_reduction(_adjCopy);

            // check cost and update details
            long long _cost = answer + adj[current_node][rem[j]] + _row_reduction.first + _column_reduction.first;
            adjCopyStorage[rem[j]] = _adjCopy;
            if (Cost.find(_cost) == Cost.end())
                Cost[_cost] = rem[j];

            // cerr <<  _row_reduction.first + _column_reduction.first << endl;
            // cerr << adj[current_node][rem[j]] << endl;
            // cerr << _cost << " " << rem[j] << endl;
            cout << "cost Branch : " << _cost << " , Node : " << rem[i] << "\n";
            print(_adjCopy);
        }

        auto miniCost = Cost.begin();
        path[miniCost->second] = pathLength;
        current_node = miniCost->second;
        pathLength++;
        answer = miniCost->first;
        adj = adjCopyStorage[miniCost->second];

        cout << "Least cost Branch : " << miniCost->first << " , Node : " << miniCost->second << "\n\n";
        print(adj);
    }

    return path;
    
}


signed main(int argc, char **argv){
    init_code();

    int n;
    cin >> n;

    vector<vector<int>>adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adj[i][j];
    print(adj);

    // implementation
    long long answer = 0;

    auto _row_reduction = row_reduction(adj);
    adj = _row_reduction.second;
    answer += _row_reduction.first;
    print(adj);
    
    auto _column_reduction = column_reduction(adj);
    adj = _column_reduction.second;
    answer += _column_reduction.first;
    print(adj);


    // final Output section
    cout << "Initial Cost after deduction : " << answer << endl;
    map<int,int> path = tsp(adj, answer);
    cout << "\n Final Cost : "  << answer << endl;
    vector<int>finalPath(n, 0);
    for (auto x : path){
      finalPath[x.second] = x.first;
    }
    cout << "Final Path : [ ";
    for (int i = 0; i < n; i++)
        cout << finalPath[i] << " ";
    cout << "]\n";
    
    return 0;


}

