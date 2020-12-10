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

Node *prev = null;

Node *convertTreeToDll(Node* root){

    if(root == null){
        return root;
    }

    Node *head = convertTreeToDll(root->left);

    if(::prev == null){
        head = root;
    }
    else{
        root->left = ::prev;
        ::prev->right = root;
    }

    ::prev = root;
    
    convertTreeToDll(root->right);

    return head;

}

int main(){

    // Node *root = null;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    // root->left->left->left = new Node(80);
    root->left->right = new Node(4);
    //root->left->right->left = new Node(20)  //root->left->right->right = new Node(10);
    root->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // root->right->right->left = new TreeNode(6);
    
    root = convertTreeToDll(root);

    Node* dummy = null;

    while(root != null){
        dummy = root;
        cout << root->key << "->";
        root = root->right;
    }
    cout << '\n';
    while(dummy != null){
        cout << dummy->key << "->";
        dummy = dummy->left; 
    }
    
    
    cout <<'\n';
    return 0;
}