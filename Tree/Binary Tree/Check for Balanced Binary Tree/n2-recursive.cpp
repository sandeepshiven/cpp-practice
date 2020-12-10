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

int heightTree(Node* root){
    if(root == null){
        return 0;        
    }else{
        return (max(heightTree(root->left), heightTree(root->right))+1);
    }

}


bool isBalanced(Node *root){

    if(root == null){
        return true;
    }
    int l = heightTree(root->left);
    int r = heightTree(root->right);

    return (abs(l-r) <= 1 &&
            isBalanced(root->left) &&
            isBalanced(root->right));

}

int main(){

    Node *root = new Node(30);
    root->left = new Node(40);
    root->left->left = new Node(50);
    root->left->right = new Node(70);
    root->left->right->left = new Node(20);
    root->left->right->right = new Node(10);
    root->right = new Node(80);
    root->right->left = new Node(5);
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(6);
    if(isBalanced(root)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout <<'\n';
    return 0;
}