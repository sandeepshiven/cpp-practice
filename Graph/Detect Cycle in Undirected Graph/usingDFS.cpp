#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>>&adj, int u, int v){
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

bool depthFirstSearchHelper(vector<vector<int>>&adj, int s, vector<bool>&visited, int parent){

    
    visited[s] = true;
    for(auto x: adj[s]){
        if(visited[x]==false){
            if(depthFirstSearchHelper(adj, x, visited, s)){
                return true;
            }
        }
        else if(x != parent){
            return true;
        }
    }
    return false;
    
    
}

bool depthFirstSearch(vector<vector<int>>&adj, int v){
    vector<bool>visited(v,false);
    for(int i = 0; i<v; i++){
        if(visited[i] == false){

            if(depthFirstSearchHelper(adj, i, visited, -1)){
                return true;
            }
            
        }
    }
    return false;
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
    
    if(depthFirstSearch(adj, v)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}