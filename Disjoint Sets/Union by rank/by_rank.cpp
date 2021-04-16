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
    else{
        return _find(parent[x]);
    }
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

int main(){

    int n, choice, x, y;
    cout << "Enter number of elements: ";
    cin >> n;
    DisjointSet st(n);
    st.initialize();
    while(1){
        cout << "What do you want to do?\n";
        cout << "1) find(x)\n";
        cout << "2) union(x, y)\n";
        cout << "3) end\n";
        cin >> choice;
        switch(choice){
        case 1:
            cout << "Enter the number you want to find: ";
            cin >> x;
            cout << "The group is: " << st._find(x) << '\n';
            break;
        case 2:
            cout << "Enter the numbers to union: ";
            cin >> x >> y;
            st._union(x, y);
            break;
        case 3:
            return 0;
        default:
            cout << "Wrong Input\n";
            break;
        }
    }
    



    return 0;
}