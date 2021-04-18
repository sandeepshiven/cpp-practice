#include <bits/stdc++.h>
using namespace std;

#define null NULL

class Node{
    public:
        char c;
        Node *left, *right;
        int count;
};
class MyComp{
    public: 
        bool operator()(Node *n1, Node *n2){
            return n1->count > n2->count;
        }
};

Node* getNode(char ch, int freq, Node *left, Node *right){
    Node* node = new Node();
    node->c = ch;
    node->count = freq;
    node->left = left;
    node->right = right;
    return node;
}

void encode(Node *root, string code, unordered_map<char, string>&huffmanCode){

    if(root == null){
        return;
    }

    if(root->left == null && root->right==null){
        huffmanCode[root->c] = code;
    }
    
    encode(root->left, code+"0", huffmanCode);
    encode(root->right, code+"1", huffmanCode);
}

void decode(Node *root, int &index, string code){
    if(root == null){
        return;
    }
    if(root->left == null && root->right == null){
        cout << root->c;
        return;
    }
    index++;
    if(code[index]=='0'){
        decode(root->left, index, code);
    }
    else{
        decode(root->right, index, code);
    }
}

void Huffman(string s){

    unordered_map<char, int>freq;
    for(auto i: s){
        freq[i]++;
    }
    priority_queue<Node*, vector<Node*>, MyComp>pq;

    for(auto i: freq){
        pq.push(getNode(i.first, i.second, null, null));
    }

    while(pq.size() > 1){
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        int sum = left->count + right->count;
        pq.push(getNode('\0', sum, left, right));
    }
    
    Node *root = pq.top();
    unordered_map<char, string>huffmanCode;
    encode(root, "",huffmanCode);
    cout << "Huffman code for the characters are: \n";
    for(auto i: huffmanCode){
        cout << i.first << " " << i.second << '\n';
    }

    cout << "The original string was: " << s;
    cout <<"\nEncoded string is:\n";
    string temp = "";
    for(auto i: s){
        temp += huffmanCode[i];
    }
    cout << temp << "\n";

    cout << "Decoded string is: \n";
    int index = -1;
    while(index < (int)temp.size()-1){
        decode(root, index, temp);
    }
    cout << "\n";
}

int main(){

    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    Huffman(s);


    return 0;
}