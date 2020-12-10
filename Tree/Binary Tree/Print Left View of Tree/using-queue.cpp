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

void printLeftView(Node* root){
    
    queue<Node *>q;
    q.push(root);
    int count = 1, sz=0;

    while(!q.empty()){

        count = q.size();
        
        cout << q.front()->key << " ";

        for(int i =0; i<count; i++){

            
        
            if(q.front()->left != null){
                q.push(q.front()->left);
            }
            if(q.front()->right != null){
                q.push(q.front()->right);
            }
            q.pop();

        }
       //cout << '\n';
        
    }
        
    
    

}

int main(){

    Node *root = new Node(30);
    root->right = new Node(50);
    root->right->left = new Node(60);
    root->right->left->right = new Node(10);
    
    printLeftView(root);
    cout <<'\n';
    return 0;
}