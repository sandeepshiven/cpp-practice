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

void printSpiralLevelOrder(Node* root){
    
    stack<Node*>s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        
        while(!s1.empty()){
            cout << s1.top()->key << " ";
            if(s1.top()->left != null){
                s2.push(s1.top()->left);
            }
            if(s1.top()->right != null){
                s2.push(s1.top()->right);
            }
            s1.pop();
        }

        while(!s2.empty()){
            cout << s2.top()->key << " ";
            
            if(s2.top()->right != null){
                s1.push(s2.top()->right);
            }
            if(s2.top()->left != null){
                s1.push(s2.top()->left);
            }
            s2.pop();
        }
        
        
    }
        
    

}

int main(){

    Node *root = new Node(10);
    root->left = new Node(20);
    //root->left->left = new Node(4);
    //root->left->left->left = new Node(8);
    //root->left->left->right = new Node(9);
    //root->left->right = new Node(5);
    root->right = new Node(30);
    root->right->right = new Node(50);
    root->right->left = new Node(40);
    root->right->right->right = new Node(80);
    root->right->left->left = new Node(60);
    root->right->left->right = new Node(70);
    
    printSpiralLevelOrder(root);
    cout <<'\n';
    return 0;
}