// 1042. Flower Planting With No Adjacent
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adjlist;
vector<int>node_colour;
int No_of_nodes;
int Mcolour;

// check if colour is valid
bool validColour(int colour, int node){
    for (int i = 0; i < adjlist[node].size(); i++)
        if(node_colour[adjlist[node][i]] == colour)
            return false;
    return true;
}

bool Mcolouring(int node){
    if (node == No_of_nodes)
        return true;

    for (int i = 1; i <= Mcolour; i++){
        if (validColour(i, node) == true){

            node_colour[node] = i;
            if (Mcolouring(node + 1) == true)
                return true;
            else
                node_colour[node] = 0;

        }
    }
    return false;
}
