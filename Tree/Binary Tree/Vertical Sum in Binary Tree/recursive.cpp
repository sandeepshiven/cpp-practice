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

void verticalSumHelper(Node *root, int hd, map<int, int>&mp){
    if(root == null){
        return;
    }
    verticalSumHelper(root->left, hd-1, mp);
    mp[hd] += root->key;
    verticalSumHelper(root->right, hd+1, mp);
}

void verticalSum(Node *root){
    if(root == null){
        return;
    }
    
    map<int, int>mp;
    verticalSumHelper(root, 0, mp);
    for(auto i: mp){
        cout << i.second << " ";
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