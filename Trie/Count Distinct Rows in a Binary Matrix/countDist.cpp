#include <bits/stdc++.h>
using namespace std;

#define null NULL

class TrieNode{
    public:
        TrieNode *child[2];
        TrieNode(){
            child[0] = null;
            child[1] = null;
        }
};

vector<vector<int>>mat;

bool insert(int i, int n, TrieNode *root){

    TrieNode *curr = root;
    bool flag = false;
    for(int j=0; j<n; j++){
        int index = mat[i][j];
        if(curr->child[index] == null){
            curr->child[index] = new TrieNode();
            flag = true;
    
        }
        curr = curr->child[index];
    }
    return flag;
}

int countDistinct(int m, int n){
    
    TrieNode *root = new TrieNode();
    int res = 0;
    for(int i=0; i<m; i++){
        if(insert(i, n, root)){
            res++;
        }
    }
    return res;
}

int main(){
    
    int m, n;
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    mat = vector<vector<int>>(m, vector<int>(n));
    for(int i=0; i<m; i++){
        cout << "Enter row " << i+1 << ": ";
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    cout << "Number of Distinct rows: " << countDistinct(m, n) <<  '\n';
    return 0;
}