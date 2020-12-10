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

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    cout << heightTree(root);
    cout <<'\n';
    return 0;
}