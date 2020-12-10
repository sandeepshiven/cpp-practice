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



int countNodes(Node *root){

    if(root == null){
        return 0;
    }
    return (countNodes(root->left)+countNodes(root->right)+1);
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->left->left = new Node(40);
    // root->right = new Node(30);
    // root->right->right = new Node(60);
    
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(6);

    cout << countNodes(root);
    cout <<'\n';
    return 0;
}