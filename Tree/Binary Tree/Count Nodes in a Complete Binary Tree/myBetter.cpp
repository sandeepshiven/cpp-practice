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

int isComplete(Node *root){

    if(root == null){
        return 0;
    }
    int lh = isComplete(root->left)+1;
    int rh = isComplete(root->right)+1;
    if(lh == rh){
        return lh;
    }
    else{
        return INT_MIN;
    }
}


int countNodes(Node *root){

    if(root == null){
        return 0;
    }
    
    int isCompleteCount = isComplete(root);
    if(isCompleteCount != INT_MIN){
        return pow(2, isCompleteCount)-1;
    }
    else{
        return (countNodes(root->left)+countNodes(root->right)+1);
    }

    
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(40);
    root->left->left->left = new Node(80);
    root->left->left->right = new Node(90);
    root->left->right = new Node(50);
    root->left->right->left = new Node(100);
    root->right = new Node(30);
    root->right->right = new Node(70);
    root->right->left = new Node(60);
    
    
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(6);

    cout << countNodes(root);
    cout <<'\n';
    return 0;
}