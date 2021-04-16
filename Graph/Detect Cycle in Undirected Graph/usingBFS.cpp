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

bool breadthFirstSearchHelper(vector<vector<int>>&adj, int s, vector<bool>&visited, int v){

    queue<int>q;
    q.push(s);
    visited[s] = true;
    vector<int>parent(v, -1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(auto x : adj[u]){
            if(visited[x]== false){
                parent[x] = u;
                q.push(x);
                visited[x] = true;
            }
            else if(parent[u] != x){
                return true;
            }
        }
    }
    return false;
    
}

bool breadthFirstSearch(vector<vector<int>>&adj, int v){
    vector<bool>visited(v,false);

    for(int i=0; i<v; i++){
        if(visited[i] == false){
            if(breadthFirstSearchHelper(adj, i, visited, v)){
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
    
    if(breadthFirstSearch(adj, v)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}