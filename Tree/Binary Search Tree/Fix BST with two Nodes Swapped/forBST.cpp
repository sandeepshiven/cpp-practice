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

void checkBST(Node *root, int &first, int &second, int &prev){
    if(root == null){
        return;
    }
    checkBST(root->left, first, second, prev);
    if(prev > root->key){
        if(first == INT_MIN){
            first = prev;
        }
        second = root->key;
    }
    prev = root->key;
    checkBST(root->right, first, second, prev);

}


int main(){

    Node *root = new Node(60);
    root->left = new Node(8);
    root->right = new Node(80);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->right->left = new Node(20);
    root->right->right = new Node(100);
    int first = INT_MIN, second = INT_MIN, prev = INT_MIN;
    checkBST(root, first, second, prev);
    cout << first << " " << second << "\n";

    return 0;
}