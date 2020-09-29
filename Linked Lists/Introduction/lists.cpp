#include<bits/stdc++.h>

using namespace std;

struct Node{

    int key;
    Node *next;
    Node(int x){
        key = x;
        next = NULL;
    }

};

Node *insertBegin(Node *head, int key){
    Node *temp = new Node(key);
    temp->next = head;
    return temp;

}

void printList(Node *head){
    //Node *curr = head;
    while(head != NULL){
        cout << head->key << "->";
        head = head->next;
    }
    cout << "END\n";

}

Node *insertEnd(Node *head, int key){

    if(head == NULL){
        return new Node(key);
    }

    Node *temp = new Node(key);
    Node *curr = head;
    while(curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}

int main(){

    Node *head = NULL;
    head = insertEnd(head, 70);
    head = insertBegin(head, 20);
    head = insertBegin(head, 5);
    head = insertEnd(head, 60);
    head = insertBegin(head, 10);
    head = insertEnd(head, 30);
    head = insertEnd(head, 50);
    head = insertEnd(head, 90);

    printList(head);
    




    return 0;
}