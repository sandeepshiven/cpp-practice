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

    queue<Node *>q;
    q.push(root);
    int l, r;

    while(!q.empty()){

        if(q.front()->left == null && q.front()->right == null){
            q.pop();
            continue;
        }

        if(q.front()->left != null){
            l = q.front()->left->key;
            q.push(q.front()->left);
        }else{
            l=0;
        }    
      
        if(q.front()->right != null){
            r = q.front()->right->key;
            q.push(q.front()->right);
        }else{
            r=0;
        }

        if(q.front()->key != l+r){
            return false;
        }


        q.pop();
        
    }

    return true;

}




int main(){

    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(2);
    root->right->left = new Node(1);
    root->right->right = new Node(2);

    
    
    
    
    if(childSum(root)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    cout <<'\n';
    return 0;
}