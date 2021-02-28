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
        void findPairHelper(Node *node, int sum, unordered_set<int>&s); 

    public:    
        BST(){
            root = null;
        }
        void insert(int n);
        bool search(int n);
        void _delete(int n);
        void findPair(int n);
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

void BST::findPair(int n){
    unordered_set<int>s;
    cout << "Pairs are: ";
    findPairHelper(root, n, s);
    cout << "\n";
}

void BST::findPairHelper(Node *root, int sum, unordered_set<int>&s){
    if(root == NULL){
        return ;
    }
    findPairHelper(root->left, sum, s);
    if(s.find(sum - root->key) != s.end()){
        cout << root->key << " " << *s.find(sum-root->key);
        return;
    }
    else{
        s.insert(root->key);
    }
    findPairHelper(root->right, sum, s);
}


int main(){
    
    BST bst;
    bst.insert(10);
    bst.insert(8);
    bst.insert(4);
    bst.insert(9);
    bst.insert(20);
    bst.insert(11);
    bst.insert(30);
    bst.insert(25);
    

    cout << "Enter the value: ";
    int n;
    cin >>n;
    bst.findPair(n);

    return 0;
}