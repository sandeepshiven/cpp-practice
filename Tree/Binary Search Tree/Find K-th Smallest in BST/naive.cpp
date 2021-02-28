#include<bits/stdc++.h>


using namespace std;

#define null NULL

class Node{

    public:
        Node *left, *right;
        int key;
        Node(int k){
            key = k;
            left = right = null;
        }
        

};

class BST{

    private:
        Node *root;
        Node *deleteHelper(Node *node, int n);
        Node *getSucc(Node *node);
        void inorderCount(int &n, Node *node); 

    public:    
        BST(){
            root = null;
        }
        void insert(int n);
        bool search(int n);
        void _delete(int n);
        void kSmall(int n);
};

void BST::insert(int n){
    if(root == null){
        root = new Node(n);
        return;
    }
    Node *curr = root;
    Node *prev = null;
    while(curr != null){
        if(curr->key == n){
            return;
        }
        else if(curr->key > n){
            prev = curr;
            curr = curr->left;
        }
        else{
            prev = curr;
            curr = curr->right;
        }
    }
    if(prev->key > n){
        prev->left = new Node(n);
    }
    else{
        prev->right = new Node(n);
    }
}

bool BST::search(int n){

    //for recursive func with space O(h)
    //-----------------------------------------------------

    // if(root == null){
    //     return false;
    // }
    // if(root->key == n){
    //     return true;
    // }
    // else if(root->key > n){
    //     return searchBST(root->left, n);
    // }
    // else{
    //     return searchBST(root->right, n);
    // }
    //------------------------------------------------------------

    // Iterative space O(1)
    Node *curr = root;
    while(curr != null){
        if(curr->key == n){
            return true;
        }
        else if(curr->key > n){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }

    }
    return false;

}

void BST::_delete(int n){
    if(root == null){
        return;
    }
    Node *curr= root;
    deleteHelper(curr, n);
    
}

Node* BST::deleteHelper(Node *node, int n){
    
    if(node == null){
        return null;
    }

    if(node->key > n){
        node->left = deleteHelper(node->left, n);
    }
    else if(node->key < n){
        node->right = deleteHelper(node->right, n);
    }
    else{
        if(node->left == null){
            Node *temp = node->right;
            delete node;
            return temp;
        }
        else if(node->right == null){
            Node *temp = node->left;
            delete node;
            return temp;
        }
        else{
            Node *temp = getSucc(node);
            node->key = temp->key;
            node->right = deleteHelper(node->right, temp->key);
            return node;
        }
    }
    return node;
}

Node * BST::getSucc(Node *node){
    Node *curr = node->right;
    while(curr != null && curr->left != null){
        curr = curr->left;
    }
    return curr;
}

void BST::kSmall(int n){
    if(root == null){
        return ;
    }
    inorderCount(n, root);
}

void BST::inorderCount(int &n, Node *node){
    if(node != null){
        inorderCount(n, node->left);
        n--;
        if(n==0){
            cout << node->key << " ";
            return;
        }
        inorderCount(n, node->right);
    }
}


int main(){
    
    BST bst;
    bst.insert(50);
    bst.insert(20);
    bst.insert(10);
    bst.insert(40);
    bst.insert(100);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    bst.insert(120);
    
    
    

    cout << "Enter the value k: ";
    int n;
    cin >>n;
    bst.kSmall(n);

    return 0;
}