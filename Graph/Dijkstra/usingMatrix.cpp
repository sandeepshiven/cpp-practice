#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>>&graph, int u, int v, int w){
    graph[u][v] = w;
    graph[v][u] = w;
}

void Dijkstra(vector<vector<int>>&graph, int V, int s){
    
    int sum,u;
    vector<int>dist(V, INT_MAX);
    vector<bool>fin(V, false);
    dist[s] = 0;
    
    for(int count=0; count<V-1; count++){
        u = -1;
        for(int i=0; i<V; i++){
            if((fin[i]==false) && (u==-1 || dist[i]<dist[u])){
                u = i;
            }
        }
        fin[u] = true;
        for(int v=0; v<V; v++){
            sum = dist[u] + graph[u][v];
            if((fin[v]==false) && (graph[u][v] != 0) && (sum > 0) && (dist[v] > sum)){
                dist[v] = sum;
            }
        }
    }

    for(auto i: dist){
        cout << i << " ";
    }
    cout << '\n';
}

int main(){

    int V, E, u, v, w; 
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>>graph(V, vector<int>(V, 0));
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
    cin >>s;
    Dijkstra(graph,V, s);
    return 0;
}