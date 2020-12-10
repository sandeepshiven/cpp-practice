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

int getMax(Node* root){
    
    if(root == null){
        return -1;
    }else{
        return max(max(root->key, getMax(root->left)), max(root->key, getMax(root->right)));
    }

}

int main(){

    Node *root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(80);
    
    cout << getMax(root);
    cout <<'\n';
    return 0;
}