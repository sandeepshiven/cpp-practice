

// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++
/*
Structure of the Node of the node of the bst 
should be as
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
// You are required to complete this function

struct NodeDetails {
    Node *ptr;
    int min, max;
};

Node* constructBst(int arr[], int n)
{
    
    // Code here
    if(n==0){
        return NULL;
    }
    
    Node *root;
    int i =0;
    queue<NodeDetails>q;
    
    NodeDetails newNode;
    
    newNode.ptr = new Node(arr[i++]);
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
	root = newNode.ptr;
	q.push(newNode);
	
	while(i != n){
	    
	    NodeDetails temp = q.front();
	    q.pop();
	    
	    if(i<n && (arr[i] < temp.ptr->data && arr[i] > temp.min )){
	        newNode.ptr = new Node(arr[i++]);
	        newNode.min = temp.min;
	        newNode.max = temp.ptr->data;
	        q.push(newNode);
	        
	        temp.ptr->left = newNode.ptr;
	        
	    }
	    
	    if(i<n && (arr[i] > temp.ptr->data && arr[i] < temp.max )){
	        newNode.ptr = new Node(arr[i++]);
	        newNode.min = temp.ptr->data;
	        newNode.max = temp.max;
	        q.push(newNode);
	        
	        temp.ptr->right = newNode.ptr;
	        
	    }
	    
	}
	return root;
}


















