#include<bits/stdc++.h>

#define NIL -1

using namespace std;



void addEdge(vector<vector<int>>&graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void DFS(vector<vector<int>>&graph, int u, vector<bool>&visited, vector<int>&disc, vector<int>&low
        , vector<int>&parent, vector<pair<int, int>>&bridges, int V){

    static int time = 0;
    

    visited[u] = true;

    disc[u] = low[u] = ++time;

    for(auto v: graph[u]){
        
        if(visited[v] == false){
            
            parent[v] = u;
            DFS(graph, v, visited, disc, low, parent, bridges, V);

            low[u] = min(low[u], low[v]);
            
            if(low[v] > disc[u]){
                bridges.push_back(make_pair(u, v));
            }
        }
        else if(v != parent[u]){
            low[u] = min(low[u], disc[v]);
        }
    }

}

void bridge(vector<vector<int>>&graph, int V){

    
    vector<bool>visited(V, false);
    vector<int>parent(V, NIL);
    vector<int>disc(V);
    vector<int>low(V);
    vector<pair<int, int>>bridges;

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            DFS(graph, i, visited, disc, low, parent, bridges, V);
        }
    }
    
    cout << "No. of bridges: " << bridges.size() << "\n";
    cout << "Bridges are:\n";
    for(auto i: bridges){
        cout << i.first << " - " << i.second << "\n";
    }
}


int main(){

    int V, E, u, v, w; 
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>>graph(V);
    cout << "Enter number of edges: ";
    cin >> E;
    for(int i=1; i<=E; i++){
        cout << "Enter edge "<< i << ": ";
        cin >> u >> v;
        
        addEdge(graph, u, v);
    }
   
    bridge(graph, V);
    cout << "\n";
    return 0;
}