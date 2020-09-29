// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */



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
            current->next = a;
            a = a->next;
        }
        else{
            current->next = b;
            b = b->next;
        }


    }

    current->next = (a==NULL)? b:a;
    return dummy->next;
}


Node* mergeSort(Node* head) {
    // your code here

    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *middle = getMiddle(head);
    Node *leftHead = head;
    Node *rightHead = middle->next;
    middle->next = NULL;

    return merge(mergeSort(leftHead), mergeSort(rightHead));
}







// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends