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


void printLeft(Node *root, int level, int &maxLevel){

    if(root == null){
        return ;
    }
    if(level > maxLevel){
        cout << root->key << " ";
        maxLevel = level;
    }
    printLeft(root->left, level+1, maxLevel);
    printLeft(root->right, level+1, maxLevel);

}


void printLeftView(Node* root){
    int maxLevel = 0;
    printLeft(root, 1, maxLevel);
}

int main(){

    Node *root = new Node(10);

    root->left = new Node(50);
    root->right = new Node(60);
    root->right->left = new Node(70);
    root->right->right = new Node(20);
    root->right->left->right = new Node(80);
    
    printLeftView(root);
    cout <<'\n';
    return 0;
}