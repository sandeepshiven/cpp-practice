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






Node* findLCA(Node* root, int a, int b){
    
    if(root == null){
        return null;
    }

    if(root->key == a || root->key == b){
        return root;
    }

    Node *lca1 = findLCA(root->left, a, b);
    Node *lca2 = findLCA(root->right, a, b);

    if(lca1 != null && lca2 != null){
        return root;
    }
    
    if(lca1 != null){
        return lca1;
    }
    else{
        return lca2;
    }

}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->left->left = new Node(60);
    root->right->right = new Node(50);
    root->right->right->right = new Node(80);
    root->right->right->left = new Node(70);

    cout << "Enter 1st number: ";
    int a, b;
    cin >> a;
    cout << "Enter 2nd number: ";
    cin >> b;
    Node *lca = findLCA(root, a, b);
    if(lca){

        cout << "The Lowest Common Ancestor is: "<< lca->key;
    }
    else{
        cout << "No common ancestors";
    }
    cout <<'\n';
    return 0;
}