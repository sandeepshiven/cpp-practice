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

int res = -1;

int burnTree(Node *root, int leaf, int &dist){

    if(root == null){
        return 0;
    }

    if(root->key == leaf){
        dist = 0;
        return 1;
    }

    int ldist = -1, rdist = -1;

    int lh = burnTree(root->left, leaf, ldist);
    int rh = burnTree(root->right, leaf, rdist);

    if(ldist != -1){
        dist = ldist + 1;
        res = max(res, rh+dist);
    }
    else if(rdist != -1){
        dist = rdist + 1;
        res = max(res, lh+dist);
    }
    return max(lh, rh)+1;

}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(30);
    root->left->left->left = new Node(40);
    // root->right = new Node(30);
    // root->right->right = new Node(60);
    
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(6);

    cout << "Enter the leaf node: ";
    int leaf;
    cin >> leaf;
    int dist = -1;
    burnTree(root, leaf, dist);
    cout << res;
    cout <<'\n';
    return 0;
}