#include<bits/stdc++.h>
#define INF INT_MAX

using namespace std;

void addEdge(vector<vector<pair<int, int>>>&adj, int u, int v, int w){
    adj[u].push_back(make_pair(v, w));

}

void printGraph(vector<int> adj[], int v){
    for(int i=0; i<v; i++){
        for(auto x: adj[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
}

vector<int> TopologicalSort(vector<vector<pair<int, int>>>&adj, int v){

    
    vector<int>indegree(v, 0);
    vector<int>res;
    for(auto i: adj){
        for(auto j: i){
            indegree[j.first]++;
        }
    }
    
    queue<int>q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        res.push_back(u);
        for(auto x : adj[u]){
            indegree[x.first]--;
            if(indegree[x.first] == 0){
                q.push(x.first);
            }
        }
    }
    
    return res;
}


vector<int> shortestPath(vector<vector<pair<int, int>>>&adj, int v, int s){
    
    
    vector<int>dist(v, INF);
    
    queue<int>q;

    vector<int>topoSort = TopologicalSort(adj, v);    
    // for(auto x: topoSort){
    //     cout << x << " ";
    // }
    // cout << '\n';
    dist[s] = 0;
    for(int i=0; i<v; i++){
        int u = topoSort[i];
        for(auto x: adj[u]){
            int sum = dist[u] + x.second;
            if((dist[x.first] > (dist[u] + x.second)) && sum > 0){
                dist[x.first] = (dist[u] + x.second);
            }
        }
    }
    return dist;
}

int main(){

    int v, e, v1, v2, w;
    cout << "Enter the number of vertex: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<vector<pair<int, int>>>adj(v);
    for(int i=1; i<=e; i++){
        cout << "Enter edge "<< i << ": ";
        cin >> v1 >> v2;
        cout << "Enter weight of edge "<<i<<": ";
        cin >> w;
        addEdge(adj, v1, v2, w);
    }
    int s;
    cout << "Enter source: ";
    cin >> s;
    vector<int>arr = shortestPath(adj, v, s);
    for(auto i: arr){
        if(i == INF){
            cout << "INF ";
        }
        else{
            cout << i << " ";
        }
    }
    cout << '\n';
    return 0;
}