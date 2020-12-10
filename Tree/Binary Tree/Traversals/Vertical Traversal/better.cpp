#include<bits/stdc++.h>

using namespace std;

#define null NULL

class Node{

    public:
        int key;
        Node *left;
        Node *right;
        Node(int k){
            key = k;
            left = right = null;
        }

};



void verticalTraversal(Node* root){
    
    map<int, vector<int>>mp;
    int hd=0;
    queue<pair<Node *, int>>q;
    q.push(make_pair(root, hd));

    while(!q.empty()){
        pair<Node *, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        Node *node = temp.first;
        mp[hd].push_back(node->key);
        if(node->left != null){
            q.push(make_pair(node->left, hd-1));
        }
        if(node->right != null){
            q.push(make_pair(node->right, hd+1));
        }
    }

    for(auto x: mp){
        for(auto y: x.second){
            cout << y << " ";
        }
        cout << '\n';
    }
    
    

}

int main(){

    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
    root->right->right->right = new Node(9); 
    verticalTraversal(root);
    cout <<'\n';
    return 0;
}