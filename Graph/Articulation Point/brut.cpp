#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>>&graph, int u, int v){
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void DFS(vector<vector<int>>&graph, int v, int s, vector<bool>&visited){

    visited[s] = true;
    for(int i=0; i<v; i++){
        if(graph[s][i] == 1 && visited[i]==false){
            DFS(graph, v, i, visited);
        }
    }    
}

void AP(vector<vector<int>>&graph, int V){

    int count = 0;
    vector<bool>visited(V, false);

    int initial_val = 0;

    for(int i=0; i<V; i++){
        if(visited[i] == false){
            DFS(graph, V, i, visited);
            initial_val++;
        }
    }

    vector<int>cp(V);
    vector<int>ap;
    for(int i =0; i<V; i++){

        for(int j = 0; j< V; j++){
            visited[j] = false;
            cp[j] = graph[i][j];
            graph[i][j] = graph[j][i] = 0;
        }
        int nval = 0;

        for(int j=0; j<V; j++){
            if(visited[j] == false && j != i){
                DFS(graph, V, j, visited);
                nval++;
            }
        }

        if(nval > initial_val){
            ap.push_back(i);
            count++;
        }

        for(int j=0; j<V; j++){
            graph[i][j] = graph[j][i] = cp[j];
        }
    }

    cout << "No. of AP: " << count << "\n";
    cout << "AP's are: ";
    for(auto i: ap){
        cout << i << " ";
    }

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
        
        addEdge(graph, u, v);
    }
   
    AP(graph, V);
    cout << "\n";
    return 0;
}