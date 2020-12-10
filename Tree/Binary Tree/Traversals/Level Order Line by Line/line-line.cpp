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
    int count = 1;

    while(!q.empty()){
        count = q.size();
        for(int i =0; i<count; i++){

            cout << q.front()->key << " ";
        
            if(q.front()->left != null){
                q.push(q.front()->left);
            }
            if(q.front()->right != null){
                q.push(q.front()->right);
            }
            q.pop();

        }
        cout << '\n';
        count = q.size();
    }
        
    

}

int main(){

    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(10);
    root->right->left = new Node(15);
    
    printLevelOrder(root);
    cout <<'\n';
    return 0;
}