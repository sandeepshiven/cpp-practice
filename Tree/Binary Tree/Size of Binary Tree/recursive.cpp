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

int calculateSize(Node* root){
    
    if(root == null){
        return 0;
    }else{
        return (calculateSize(root->left)+calculateSize(root->right)+1);
    }

}

int main(){

    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(10);
    root->right->left = new Node(15);
    
    cout << calculateSize(root);
    cout <<'\n';
    return 0;
}