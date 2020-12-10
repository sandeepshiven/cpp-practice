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

void serialize(Node *root, vector<int>&arr){

    if(root == null){
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left, arr);
    serialize(root->right, arr);
}

Node* deserialize(vector<int>&arr, int &i){
    
    if(i == arr.size() || arr[i] == -1){
        return null;
    }
    Node *root = new Node(arr[i]);
    root->left = deserialize(arr, ++i);
    root->right = deserialize(arr, ++i);
    return root;
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    // root->right = new Node(30);
    // root->right->left = new Node(40);
    // root->right->right = new Node(50);
    // root->left->left = new Node(30);
    // root->left->left->right = new Node(40);

    preorderTraversal(root);
    cout <<'\n';
    vector<int>a;
    serialize(root, a);
    int x=0;
    root = deserialize(a, x);

    cout << "-------------------------------\n";
    preorderTraversal(root);
    cout <<'\n';
    return 0;
}