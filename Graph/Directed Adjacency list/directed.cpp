#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>>&adj, int u, int v){
    adj[u].push_back(v);
}

void printGraph(vector<vector<int>>&adj, int v){
    for(int i=0; i<v; i++){
        for(auto x: adj[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main(){


    int v, e, x, y;
    cout << "Enter number of vertex: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<int>>adj(v);

    for(int i=1; i<=e; i++){
        cout << "Enter edge "<<i<<": ";
        cin >> x >> y;
        addEdge(adj, x, y);
    }
    printGraph(adj, v);


    return 0;
}