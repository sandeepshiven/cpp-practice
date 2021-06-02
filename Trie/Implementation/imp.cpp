#include <bits/stdc++.h>
using namespace std;
#define null NULL

class TrieNode{
    public:
        TrieNode *child[26];
        bool isEnd;
        TrieNode(){
            isEnd = false;
            for(int i=0; i<26; i++){
                child[i] = null;
            }
        }
};


void insert(string &key, TrieNode *root){
    TrieNode *curr = root;
    for(int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        if(curr->child[index] == null){
            curr->child[index] = new TrieNode();
        }
        curr = curr->child[index];
    }
    curr->isEnd = true;
}

bool search(string &key, TrieNode *root){
    TrieNode *curr = root;
    for(int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        if(curr->child[index] == null){
            return false;
        }
        curr = curr->child[index];
    }
    return curr->isEnd;
}

bool isEmpty(TrieNode *root){
    for(int i=0; i<26; i++){
        if(root->child[i] != null){
            return false;
        }
    }
    return true;
}

TrieNode* deleteKey(string &key, int i, TrieNode *root){
    if(root == null){
        return null;
    }
    if(i == key.length()){
        root->isEnd = false;
        if(isEmpty(root)){
            delete(root);
            root = null;
        }
        return root;
    }
    int index = key[i] - 'a';
    root->child[index] = deleteKey(key, i+1, root->child[index]);

    if(isEmpty(root) && root->isEnd == false){
        delete(root);
        root = null;
    }
    return root;
}

int main(){
    
    TrieNode *root = new TrieNode();
    vector<string>arr = {"bad", "geek", "bat", "geeks", "cat", "cut", "zoo", "an", "ant", "and"};
    for(auto i: arr){
        insert(i, root);
    }
    search(*(new string("bat")), root) ? cout << "YES\n": cout << "NO\n";
    search(*(new string("gee")), root) ? cout << "YES\n": cout << "NO\n";
    deleteKey(arr[7], 0, root);
    search(arr[7], root) ? cout<< "YES\n" : cout << "NO\n";
    search(arr[8], root) ? cout << "YES\n" : cout << "NO\n";

    return 0;
}