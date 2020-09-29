// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends


/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


// Function to merge two DLLs

Node* getMiddle(Node *head){
    if(head == NULL){
        return head;
    }
    Node *slow= head, *fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* a, Node* b){

    Node *dummy = new Node(0);
    Node *current = dummy;
    for( ; a!=NULL && b!=NULL; current=current->next){

        if(a->data <= b->data){
            if(current->next == NULL){
                current->next = a;
            }
            else{
                a->prev = current;
                current->next = a;
            }
            a = a->next;
        }
        else{
            if(current->next == NULL){
                current->next = b;
            }
            else{
                b->prev = current;
                current->next = b;
            }
            b = b->next;
        }


    }
    ((a==NULL)? b:a)->prev = current;
    current->next = (a==NULL)? b:a;
    return dummy->next;
}

struct Node *sortDoubly(struct Node *head)
{
	// Your code here

    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *middle = getMiddle(head);
    Node *leftHead = head;
    Node *rightHead = middle->next;
    rightHead->prev = NULL;
    leftHead->prev = NULL;
    middle->next = NULL;

    return merge(sortDoubly(leftHead), sortDoubly(rightHead));
}


// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends