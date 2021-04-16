#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<pair<int, int>>>&graph, int u, int v, int w){
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

void primMST(vector<vector<pair<int, int>>>&graph, int V){
    vector<bool>inMST(V, false);
    vector<int>key(V, INT_MAX);
    vector<pair<int, int>>MST(V);
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;

    int res = 0;
    key[0] = 0;
    pq.push(make_pair(0, 0));
    
    while(!pq.empty()){
        pair<int,int> u = pq.top();
        pq.pop();
        //res += u.first;
        inMST[u.second] = true;
        for(auto v: graph[u.second]){
            if((inMST[v.first]==false) && (key[v.first] > v.second)){
                key[v.first] = v.second;
                MST[v.first].first = u.second;
                MST[v.first].second = v.second;
                pq.push(make_pair(v.second, v.first));
            }
        }
    }


    cout << "Edge\tWeight\n";
    for(int i=0; i<V; i++){
        cout << i << " - " << MST[i].first << "\t" << MST[i].second;
        cout << "\n";
        res += MST[i].second;
    }
    cout << "Total: "<< res<<"\n";
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
    primMST(graph,V);
    return 0;
}