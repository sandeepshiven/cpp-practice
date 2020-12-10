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

void printKDistance(Node* root, int k){
    if(k != 0){
        if(root->left != null){
            printKDistance(root->left, k-1);

        }
        if(root->right != null){

            printKDistance(root->right, k-1);
        }
    }else{
        cout << root->key << " ";
        
    }
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->left = new Node(11);
    root->right->right->right = new Node(12);
    cout << "Enter the value of K: ";
    int k;
    cin >> k; 
    printKDistance(root, k);
    cout <<'\n';
    return 0;
}