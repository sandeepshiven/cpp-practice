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



void TSHelper(vector<vector<int>>&adj, stack<int>&st, vector<bool>&visited, int s){

    visited[s] = true;
    for(auto u: adj[s]){
        if(visited[u] == false){
            TSHelper(adj, st, visited, u);
        }
    }
    st.push(s);
    
}

void TopologicalSort(vector<vector<int>>&adj, int v){
    stack<int>st;
    vector<bool>visited(v,false);
    for(int i=0; i<v; i++){
        if(visited[i] == false){
            TSHelper(adj, st, visited, i);
        }
    }

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
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
    
    TopologicalSort(adj, v);
    cout << "\n";

    return 0;
}