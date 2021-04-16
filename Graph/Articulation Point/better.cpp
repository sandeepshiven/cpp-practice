#include<bits/stdc++.h>

#define NIL -1

using namespace std;



void addEdge(vector<vector<int>>&graph, int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void DFS(vector<vector<int>>&graph, int u, vector<bool>&visited, vector<int>&disc, vector<int>&low
        , vector<int>&parent, vector<bool>&ap, int V){

    static int time = 0;
    int children = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    for(auto v: graph[u]){
        
        if(visited[v] == false){
            children++;
            parent[v] = u;
            DFS(graph, v, visited, disc, low, parent, ap, V);

            low[u] = min(low[u], low[v]);

            if(parent[u] == NIL && children > 1){
                ap[u] = true;
            }
            else if(parent[u] != NIL && low[v] >= disc[u]){
                ap[u] = true;
            }
        }
        else if(v != parent[u]){
            low[u] = min(low[u], disc[v]);
        }
    }

}

void AP(vector<vector<int>>&graph, int V){

    
    vector<bool>visited(V, false);
    vector<int>parent(V, NIL);
    vector<int>disc(V);
    vector<int>low(V);
    vector<bool>ap(V, false);

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            DFS(graph, i, visited, disc, low, parent, ap, V);
        }
    }
    
    cout << "No. of AP: " << count(ap.begin(), ap.end(), true) << "\n";
    cout << "AP's are: ";
    for(int i=0; i<V; i++){
        if(ap[i]){
            cout << i << " ";
        }
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
   
    AP(graph, V);
    cout << "\n";
    return 0;
}