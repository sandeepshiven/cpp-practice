#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>>&graph, int u, int v, int w){
    graph[u][v] = w;
    graph[v][u] = w;
}

void primMST(vector<vector<int>>&graph, int V){
    vector<bool>inMST(V, false);
    vector<int>key(V, INT_MAX);
    int res = 0;
    vector<pair<int, int>>MST(V);
    key[0] = 0;

    for(int count=0; count < V; count++){

        int u = -1;
        for(int i =0; i<V; i++){
            if((inMST[i]==false) && (u == -1 || key[i]<key[u])){
                u = i;
            }
        }
        inMST[u] = true;
        res += key[u];

        for(int v=0; v<V; v++){
            if((inMST[v]==false) && (graph[u][v] != 0) && (graph[u][v] < key[v])){
                key[v] = graph[u][v];
                MST[v].first = u;
                MST[v].second = key[v];
            }
        }
    }
    cout << "Edge\tWeight\n";
    for(int i=0; i<V; i++){
        cout << i << " - " << MST[i].first << "\t" << MST[i].second;
        cout << "\n";
    }
    cout << "Total: "<< res<<"\n";
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
    primMST(graph,V);
    return 0;
}