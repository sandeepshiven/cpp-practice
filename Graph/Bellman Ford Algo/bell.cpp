#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<pair<int, int>>>&graph, int u, int v, int w){
    graph[u].push_back(make_pair(v, w));
    
}

void Dijkstra(vector<vector<pair<int, int>>>&graph, int V, int s){
    

    
    vector<int>dist(V, INT_MAX);
    dist[s] = 0;
    for(int i=0; i<V-1; i++){
        for(int u=0; u<V; u++){
            for(auto v: graph[u]){
                int sum = dist[u] + v.second;
                if(sum != INT_MIN && dist[v.first] > sum){
                    dist[v.first] = sum;
                }
            }
        }
    }

    for(int u=0; u<V; u++){
        for(auto v: graph[u]){
            int sum = dist[u] + v.second;
            if(sum != INT_MIN && dist[v.first] > sum){
                cout << "Negative Weight Cycle Found\n";
                return;
            }
        }
    }
    

    for(auto i: dist){
        cout << i << " ";
    }
    cout << "\n";
    
}

int main(){

    int V, E, u, v, w; 
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<pair<int, int>>>graph(V);
    cout << "Enter number of edges: ";
    cin >> E;
    for(int i=1; i<=E; i++){
        cout << "Enter edge "<< i << ": ";
        cin >> u >> v;
        cout << "Enter weight: ";
        cin >> w;
        addEdge(graph, u, v, w);
    }
    cout << "Enter source: ";
    int s;
    cin >> s;
    Dijkstra(graph,V, s);
    return 0;
}