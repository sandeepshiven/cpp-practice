#include<bits/stdc++.h>

using namespace std;

#define null NULL

class TreeNode{

    public:
        int key;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int k){
            key = k;
            left = right = null;
        }

};

class DllNode{

    public:
        int key;
        DllNode *prev;
        DllNode *next;
        DllNode(int k){
            key = k;
            prev = next = null;
        }
};

DllNode *convertTreeToDll(TreeNode* root, DllNode *head){

    if(root == null){
        return head;
    }
    
    if(root->left == null){

        DllNode *temp = new DllNode(root->key);
        temp->prev = head;
        head->next = temp;
        return temp;
    }
    DllNode *temp = new DllNode(root->key);
    DllNode *previousNode = convertTreeToDll(root->left, head); 
    temp->prev = previousNode;
    previousNode->next = temp;
    DllNode *nextNode = convertTreeToDll(root->right, temp);
    
    return nextNode;

}

int main(){

    // Node *root = null;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    // root->left->left->left = new TreeNode(80);
    root->left->right = new TreeNode(4);
    //root->left->right->left = new TreeNode(20);
    //root->left->right->right = new TreeNode(10);
    root->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    // root->right->right->left = new TreeNode(6);
    
    DllNode *head = new DllNode(-453254325), *temp; 
    head = convertTreeToDll(root, head);
    
    while(head != null){
        cout << head->key << "->";
        temp = head;
        head = head->prev;
    }
    cout << '\n';
    temp = temp->next;
    while(temp != null){
        cout << temp->key << "->";
        temp = temp->next;
    }
    

    
    cout <<'\n';
    return 0;
}