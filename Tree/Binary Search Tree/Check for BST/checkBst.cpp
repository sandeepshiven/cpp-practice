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

bool checkBST(Node *root, int min, int max){
    if(root == null){
        return true;
    }
    return((root->key>min && root->key < max) && 
            checkBST(root->left, min, root->key) 
            && checkBST(root->right, root->key, max));
}


int main(){

    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(30);
    if(checkBST(root, INT_MIN, INT_MAX)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    return 0;
}