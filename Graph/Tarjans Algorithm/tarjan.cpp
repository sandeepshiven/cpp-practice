#include<bits/stdc++.h>

#define NIL -1

using namespace std;



void addEdge(vector<vector<int>>&graph, int u, int v){
    graph[u].push_back(v);
    
}

void DFS(vector<vector<int>>&graph, int u, vector<int>&disc, vector<int>&low
        , stack<int>&st, vector<bool>&stackMember, int V){

    static int time = 0;
    

    stackMember[u] = true;
    st.push(u);
    disc[u] = low[u] = ++time;

    for(auto v: graph[u]){
        
        if(disc[v] == NIL){            
            
            DFS(graph, v, disc, low, st, stackMember, V);

            low[u] = min(low[u], low[v]);
            
        }
        else if(stackMember[v] == true){
            low[u] = min(low[u], disc[v]);
        }
    }
    int temp=-1;

    if(low[u] == disc[u]){
        while(temp != u){
            temp = st.top();
            st.pop();
            stackMember[temp] = false;
            cout << temp << " ";
        }
        cout << '\n';
    }

}

void bridge(vector<vector<int>>&graph, int V){

    
    vector<bool>stackMember(V, false);
    
    vector<int>disc(V, NIL);
    vector<int>low(V, NIL);
    stack<int>st;

    for(int i=0; i<V; i++){
        if(disc[i] == NIL){
            DFS(graph, i, disc, low, st, stackMember, V);
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
   
    bridge(graph, V);
    cout << "\n";
    return 0;
}