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
        void findPairHelper(Node *node, vector<int>&v); 

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
    vector<int>arr;
    findPairHelper(root, arr);
    cout << "Pairs are: ";
    for(int i=0, j=arr.size()-1; i<arr.size() && j >= 0 && i< j;){
        if(arr[i]+arr[j] == n){
            cout << arr[i] << " " << arr[j]<<'\n';
            return;
        }
        else if(arr[i]+ arr[j] > n){
            j--;
        }
        else{
            i++;
        }
    }
    cout << "NILL\n";
}

void BST::findPairHelper(Node *root, vector<int>&arr){
    if(root == NULL){
        return ;
    }
    findPairHelper(root->left, arr);
    arr.push_back(root->key);
    findPairHelper(root->right, arr);
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