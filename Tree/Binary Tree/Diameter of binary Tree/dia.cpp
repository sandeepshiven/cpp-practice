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

int heightTree(Node* root){
    if(root == null){
        return 0;        
    }else{
        return (max(heightTree(root->left), heightTree(root->right))+1);
    }

}

int findDiameter(Node* root){
    
    if (root == null){
        return 0;
    }
    int d1 = 1 + heightTree(root->left) + heightTree(root->right);
    
    int d2 = findDiameter(root->left);
    int d3 = findDiameter(root->right);

    return max (d1, max(d2,d3));
    

}

int res = 0;
int betterSolution(Node *root){
    if(root == null){
        return 0;
    }
    int lh = betterSolution(root->left);
    int rh = betterSolution(root->right);
    res = max(res, (1+lh+rh));
    return (max(lh, rh) +1);
}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    //root->left->left = new Node(4);
    //root->left->left->left = new Node(8);
    //root->left->left->right = new Node(9);
    //root->left->right = new Node(5);
    root->right = new Node(30);
    root->right->right = new Node(60);
    root->right->left = new Node(40);
    root->right->right->right = new Node(70);
    root->right->left->left = new Node(60);
    
    
    cout << findDiameter(root);
    cout <<'\n';
    betterSolution(root);
    cout << res;
    cout <<'\n';
    return 0;
}