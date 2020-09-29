#include<bits/stdc++.h>

using namespace std;

#define null NULL

struct Node{

    int key;
    Node *next;
    Node(int x){
        key = x;
        next = null;
    }

};

Node *insertEnd(Node *head, int key){

    if(head == null){
        return new Node(key);
    }

    Node *temp = new Node(key);
    Node *curr = head;
    while(curr->next != null)
    {
        curr = curr->next;
    }
    curr->next = temp;
    return head;
}


void printList(Node *head){
    //Node *curr = head;
    while(head != null){
        cout << head->key << "->";
        head = head->next;
    }
    cout << "END\n";

}

Node *reverseList(Node *curr, Node *prev){

    
    if(curr == null){
        return prev;
    }
    Node *next = curr->next;
    curr->next = prev;

    return reverseList(next, curr);    

}

int main(){

    Node *head = NULL;
    

    cout << "How many nodes you want ? : ";
    int n, temp;
    cin >>n;
    cout<< "Insert "<<n<<" nodes: ";
    while(n--){
        cin >>temp;
        head = insertEnd(head, temp);
    }
    
    printList(head);

    head = reverseList(head, null);

    printList(head);
    




    return 0;
}