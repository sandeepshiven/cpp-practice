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

void verticalSum(Node *root){
    if(root == null){
        return;
    }

    map<int, vector<int>>mp;
    queue<pair<Node *, int>>q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        int hd = temp.second;
        Node* node = temp.first;
        mp[hd].push_back(node->key);
        if(node->left != null){
            q.push(make_pair(node->left, hd-1));
        }
        if(node->right != null){
            q.push(make_pair(node->right, hd+1));
        }
    }

    for(auto i: mp){
        cout << accumulate(i.second.begin(), i.second.end(), 0)
                << " ";
    }
    cout << '\n'; 
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(15);
    root->right = new Node(25);
    root->left->left = new Node(35);
    root->left->left->left =  new Node(40);
    root->left->right = new Node(20);
    root->left->right->right = new Node(75);
    root->left->right->right->right = new Node(80);
    verticalSum(root);
    return 0;
}