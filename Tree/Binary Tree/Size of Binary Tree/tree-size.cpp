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

int calculateSize(Node* root){
    
    queue<Node *>q;
    q.push(root);
    int count = 1, sz=0;

    while(!q.empty()){

        count = q.size();
        sz += count;

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
       //cout << '\n';
        
    }
        
    return sz;
    

}

int main(){

    Node *root =null;
    
    cout << calculateSize(root);
    cout <<'\n';
    return 0;
}