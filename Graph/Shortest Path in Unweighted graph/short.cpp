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

vector<int> shortestPath(vector<vector<int>>&adj, int v, int s){
    vector<bool>visited(v,false);
    vector<int>dist(v, INT_MAX);
    queue<int>q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto x : adj[u]){
            if(visited[x]== false){
                dist[x] = dist[u]+1;
                q.push(x);
                visited[x] = true;
            }
        }
    }
    return dist;
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
    
    vector<int>arr = shortestPath(adj, v, 0);
    for(auto i: arr){
        cout << i << " ";
    }
    cout << '\n';
    return 0;
}