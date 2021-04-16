#include<bits/stdc++.h>

using namespace std;


class DisjointSet{

    private:
        int *parent;
        int *rank;
        int s;
    public:
        DisjointSet(int n);
        int _find(int x);
        void _union(int x, int y);
        void initialize();

};

DisjointSet::DisjointSet(int n){
    s = n;
    parent = new int[s];
    rank = new int[s];
}

void DisjointSet::initialize(){
    for(int i=0; i<s; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int DisjointSet:: _find(int x){
    if(x == parent[x]){
        return x;
    }
    
    parent[x] = _find(parent[x]);
    
    return parent[x];
}

void DisjointSet:: _union(int x, int y){

    int x_rep = _find(x);
    int y_rep = _find(y);

    if(x_rep == y_rep){
        return;
    }
    else if(rank[x_rep] > rank[y_rep]){
        parent[y_rep] = x_rep;
    }
    else if(rank[y_rep] > rank[x_rep]){
        parent[x_rep] = y_rep;
    }
    else{
        parent[y_rep] = x_rep;
        rank[x_rep]++;
    }
}


class Edge{

    public:
        int src, dest, wt;
        Edge(int s, int d, int w){
            src = s;
            dest = d;
            wt = w;
        }
};



bool myComp(Edge e1, Edge e2){
    return e1.wt < e2.wt;
}



void Kruskal(vector<Edge>&arr, int E, int V){

    DisjointSet dis(V);
    dis.initialize();
    
    vector<Edge>MST;
    int res = 0;

    sort(arr.begin(), arr.end(), myComp);

    for(int i=0, s=0; s<V-1; i++){
        
        Edge e = arr[i];
        
        int x = dis._find(e.src);
        int y = dis._find(e.dest);

        if(x != y){
            MST.push_back(e);
            res += e.wt;
            dis._union(x, y);
            s++; 
        }

    }
    cout << "Total weight of MST is: " << res << '\n';
    cout << "Edges in MST are:\n";
    for(auto e: MST){
        cout << e.src << " - "<< e.dest << " -- wt("<<e.wt<<")\n"; 
    }

}


int main(){

    int e, v, x, y, w;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<Edge>arr;
    for(int i=0; i<e; i++){
        cout << "Enter edge " << i+1 << ": ";
        cin >> x >> y;
        cout << "Enter weight: ";
        cin >> w;
        arr.push_back(Edge(x, y, w));
    }
    Kruskal(arr, e, v);
    return 0;
}