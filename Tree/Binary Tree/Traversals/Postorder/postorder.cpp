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

void postorderTraversal(Node* root){
    if(root != null){        
        
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->key << " ";
    }
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    postorderTraversal(root);
    cout <<'\n';
    return 0;
}