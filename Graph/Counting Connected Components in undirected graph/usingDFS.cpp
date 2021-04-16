#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int v){
    for(int i=0; i<v; i++){
        for(auto x: adj[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
}

void depthFirstSearchHelper(vector<vector<int>>&adj, int v, int s, vector<bool>&visited){

    //cout << s << " ";
    visited[s] = true;
    for(auto x: adj[s]){
        if(visited[x]==false){
            depthFirstSearchHelper(adj, v, x, visited);
        }
    }
    
    
}


int depthFirstSearch(vector<vector<int>>&adj, int v){
    vector<bool>visited(v,false);
    int res =0;
    for(int i = 0; i<v; i++){
        if(visited[i] == false){

            depthFirstSearchHelper(adj, v, i, visited);
            res++;
            //cout << "\n";
        }
    }
    return res;
}

int main(){

    int v, e, v1, v2;
    cout << "Enter the number of vertex: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<vector<int>>adj(v);
    for(int i=1; i<=e; i++){
        cout << "Enter edge "<< i << ": ";
        cin >> v1 >> v2;
        addEdge(adj, v1, v2);
    }
    
    cout << depthFirstSearch(adj, v) << "\n";

    return 0;
}