

#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u][v] = 1;
   
}

void printGraph(vector<int> adj[], int v){
    for(int i=0; i<v; i++){
        for(auto x: adj[i]){
            cout << x << " ";
        }
        cout << "\n";
    }
}



void DSHelper(vector<vector<int>>&adj, stack<int>&st, vector<bool>&visited, int s, int v){

    visited[s] = true;
    
    for(int i=0; i<v; i++){
        if(adj[s][i] == 1 && visited[i] == false){
            DSHelper(adj, st, visited, i, v);
        }
    }

    st.push(s);
    
}

vector<int> decreaseSort(vector<vector<int>>&adj, int v){
    vector<int>res;
    stack<int>st;
    vector<bool>visited(v,false);
    for(int i=0; i<v; i++){
        if(visited[i] == false){
            DSHelper(adj, st, visited, i, v);
        }
    }

    while(!st.empty()){
        //cout << st.top() << " ";
        res.push_back(st.top());
        st.pop();
    }
    return res;
}

void transpose(vector<vector<int>>&adj, int v){

    for(int i=0; i<v; i++){
        for(int j=i+1; j<v; j++){
            swap(adj[i][j], adj[j][i]);
        }
    }

}


void DFS(vector<vector<int>>&adj, vector<bool>&visited, int s, int v){

    cout << s << " ";
    visited[s] = true;

    for(int i = 0; i<v; i++){
        if(adj[s][i]==1 && visited[i] == false){
            DFS(adj, visited, i, v);
        }
    }

}

void Kosaraju(vector<vector<int>>&adj, int v){
    vector<int>decOrder = decreaseSort(adj, v);
    
    transpose(adj, v);
    vector<bool>visited(v, false);

    for(int i=0; i<v; i++){
        if(visited[decOrder[i]] == false){
            DFS(adj, visited, decOrder[i], v);
            cout << '\n';
        }
    }

}

int main(){

    int v, e, v1, v2;
    cout << "Enter the number of vertex: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<vector<int>>adj(v, vector<int>(v,0));
    for(int i=1; i<=e; i++){
        cout << "Enter edge "<< i << ": ";
        cin >> v1 >> v2;
        addEdge(adj, v1, v2);
    }
    
    Kosaraju(adj, v);
    cout << "\n";

    return 0;
}