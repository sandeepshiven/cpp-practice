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

void printLevelOrder(Node* root){
    
    queue<Node *>q;
    q.push(root);
    

    while(!q.empty()){

        cout << q.front()->key << " ";
        
        if(q.front()->left != null){
            q.push(q.front()->left);
        }
        if(q.front()->right != null){
            q.push(q.front()->right);
        }
        q.pop();
    }
    

}

int main(){

    Node *root = new Node(8);
    root->right = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(3);
    printLevelOrder(root);
    cout <<'\n';
    return 0;
}