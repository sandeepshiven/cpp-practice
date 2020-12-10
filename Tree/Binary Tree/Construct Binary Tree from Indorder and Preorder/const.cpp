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

void inorderTraversal(Node* root){
    if(root != null){
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node* root){
    if(root != null){
        
        cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int preIndex = 0;

Node* buildTreeHelper(vector<int> &in, vector<int>&pre, int is, int ie){

    if(is > ie){
        return null;
    }

    Node *root = new Node(pre[preIndex++]);

    int index;

    for(int i=is; i<=ie; i++){
        if(in[i] == root->key){
            index = i;
            break;
        }
    }

    root->left = buildTreeHelper(in, pre, is, index-1);
    root->right = buildTreeHelper(in, pre, index+1, ie);
    
    return root;
}

Node* buildTree(vector<int> &in, vector<int>&pre, int n){

    return buildTreeHelper(in, pre, 0, n-1);

}




int main(){

    cout << "Enter number of nodes in tree: ";
    int n;
    cin >> n;
    vector<int>in(n), pre(n);
    cout << "Enter Inorder Traversal: ";
    for(int i=0; i<n; i++){
        cin >> in[i];
    }
    cout << "Enter Preorder Traversal: ";
    for(int i=0; i<n; i++){
        cin >> pre[i];
    }

    Node *root = buildTree(in, pre, n);

    cout << "----------------------------------------";
    cout <<'\n';

    inorderTraversal(root);

    cout <<'\n';

    preorderTraversal(root);

    cout <<'\n';
    return 0;
}