#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
}

void printGraph(vector<int> adj[], int v){
    for(int i=0; i<v; i++){
        for(auto x: adj[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
}


bool dfsHelper(vector<vector<int>>&adj, int s, vector<bool>&visited, vector<bool>&recursionStack){

    visited[s] = true;
    recursionStack[s] = true;
    for(auto u: adj[s]){
        if((visited[u] == false) && dfsHelper(adj, u, visited, recursionStack)){
            return true;
        }
        else if(recursionStack[u] == true){
            return true;
        }
    }
    recursionStack[s] = false;
    return false;

}

bool dfs(vector<vector<int>>&adj, int v){
    vector<bool>visited(v, false);
    vector<bool>recursionStack(v, false);

    for(int i=0; i<v; i++){
        if(visited[i] == false){
            if(dfsHelper(adj, i, visited, recursionStack)){
                return true;
            }
        }
    }
    return false;
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
    if(dfs(adj, v)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }


    return 0;
}