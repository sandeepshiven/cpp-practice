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

int calculateHeight(Node* root){
    
    queue<Node *>q;
    q.push(root);
    int count = 0, res = 0;

    while(!q.empty()){
        count = q.size();
        res = max(res, count);
        for(int i =0; i<count; i++){

            //cout << q.front()->key << " ";
        
            if(q.front()->left != null){
                q.push(q.front()->left);
            }
            if(q.front()->right != null){
                q.push(q.front()->right);
            }
            q.pop();

        }
        
    }
        
    return res;
    
    

}

int main(){

    Node *root = null;

    // Node *root = new Node(8);
    // root->left = new Node(30);
    // root->left->left = new Node(90);
    // // root->left->left->left = new Node(80);
    // root->left->right = new Node(100);
    // //root->left->right->left = new Node(20);
    // //root->left->right->right = new Node(10);
    // root->right = new Node(20);
    // root->right->left = new Node(70);
    // root->right->right = new Node(340);
    // // root->right->right->left = new Node(6);
    
    cout << calculateHeight(root);
    cout <<'\n';
    return 0;
}