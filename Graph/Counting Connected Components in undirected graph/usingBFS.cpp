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

void breadthFirstSearchHelper(vector<vector<int>> &adj, int v, int s, vector<bool>&visited){

    queue<int>q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        //cout << u << " ";
        for(auto x : adj[u]){
            if(visited[x]== false){

                q.push(x);
                visited[x] = true;
            }
        }
    }
    //cout << "\n";
}

int breadthFirstSearch(vector<vector<int>>&adj, int v){
    vector<bool>visited(v,false);
    int res = 0;
    for(int i=0; i<v; i++){
        if(visited[i] == false){
            breadthFirstSearchHelper(adj, v, i, visited);
            res++;
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
    
    cout << breadthFirstSearch(adj, v) << "\n";

    return 0;
}