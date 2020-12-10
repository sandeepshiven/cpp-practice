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


bool childSum(Node *root){

    if(root == null){
        return true;
    }

    if(root->left == null && root->right == null){
        return true;
    }

    int sum =0;
    if(root->left != null){
        sum += root->left->key;
    }
    if(root->right != null){
        sum += root->right->key;
    }
    
    return (root->key == sum &&
            childSum(root->left) &&
            childSum(root->right));
    

}




int main(){

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->right->left = new Node(2);
    //root->left->right = new Node(5);

    
    
    
    
    if(childSum(root)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout <<'\n';
    return 0;
}