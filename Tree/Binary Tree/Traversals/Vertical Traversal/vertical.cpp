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

void printVertical(Node *root, int level, int hd){
    if(root == null){
        return;
    }
    if(hd == level){
        cout << root->key << " "; 
    }
    printVertical(root->left, level, hd-1);
    printVertical(root->right, level, hd+1);
    
}

void findMinMax(Node *root, int hd, int &minL, int &maxR){
    if(root == null){
        
        return;
    }
    minL = min(minL, hd);
    maxR = max(maxR, hd);
    findMinMax(root->left, hd-1, minL, maxR);
    findMinMax(root->right, hd+1, minL, maxR);
}

void verticalTraversal(Node* root){
    
    int minL =0, maxR=0;
    findMinMax(root, 0, minL, maxR);
    cout << "--------------------------------\n" << minL << " " << maxR << "\n------------------------------\n";
    for(int vLevel = minL; vLevel <= maxR; vLevel++){
        printVertical(root, vLevel, 0);
        cout << '\n';
    }
    

}

int main(){

    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    root->right->left->right = new Node(8); 
    root->right->right->right = new Node(9); 
    verticalTraversal(root);
    cout <<'\n';
    return 0;
}