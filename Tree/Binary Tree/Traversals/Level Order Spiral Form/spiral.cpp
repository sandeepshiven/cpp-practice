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
    
    deque<Node *>q;
    q.push_front(root);
    int count = 1;
    bool flag = false;

    while(!q.empty()){
        count = q.size();

        if(flag){
            flag = !flag;
            for(int i=0; i<count; i++){
                cout << q.back()->key << " ";
                q.push_front(q.back());
                q.pop_back();
            }

            for(int i=0; i<count; i++){
                if(q.front()->left != null){
                    q.push_back(q.front()->left);
                }
                if(q.front()->right != null){
                    q.push_back(q.front()->right);
                }
                q.pop_front();
            }

        }
        else{
            flag = !flag;

            for(int i=0; i<count; i++){
                if(q.front()->left != null){
                    q.push_back(q.front()->left);
                }
                if(q.front()->right != null){
                    q.push_back(q.front()->right);
                }
                cout << q.front()->key << " ";
                q.pop_front();
            }
            
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