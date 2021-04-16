#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<pair<int, int>>>&graph, int u, int v, int w){
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

void Dijkstra(vector<vector<pair<int, int>>>&graph, int V, int s){
    

    vector<bool>fin(V, false);
    vector<int>dist(V, INT_MAX);
    int sum;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;

    
    dist[s] = 0;
    pq.push(make_pair(0, s));
    
    while(!pq.empty()){
        pair<int,int> u = pq.top();
        pq.pop();
        //res += u.first;
        
        for(auto v: graph[u.second]){
            sum = dist[u.second] + v.second;
            if((sum > 0) && (dist[v.first] > sum)){
                
                dist[v.first] = sum;
                
                pq.push(make_pair(dist[v.first], v.first));
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