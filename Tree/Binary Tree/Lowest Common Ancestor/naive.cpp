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


bool findPath(Node *root, vector<Node*>&path, int n){

    if(root == null){
        return false;
    }

    path.push_back(root);

    if(root->key == n){
        return true;
    }

    if(findPath(root->left, path, n) || findPath(root->right, path, n)){
        return true;
    }
    
    path.pop_back();
    return false;

}



Node* findLCA(Node* root, int a, int b){
    
    vector<Node*>path1, path2;

    if(findPath(root, path1, a) == false ||
        findPath(root, path2, b) == false){
            return null;
        }

    for(int i=0; i<path1.size()-1 && i<path2.size()-1; i++){
        if(path1[i+1] != path2[i+1]){
            return path1[i];
            
        }
    }
    int k = (path1.size() <= path2.size())? path1.size(): path2.size();
    if(path1[k-1] == path2[k-1]){
        return path1[k-1];
    } 
    return null;

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