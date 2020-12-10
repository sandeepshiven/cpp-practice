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

void preorderTraversal(Node* root){
    if(root != null){
        
        cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    preorderTraversal(root);
    cout <<'\n';
    return 0;
}