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

int nthEndList(Node *head, int pos){
    if(head == null){
        return INT_MIN;
    }

    Node *slow=head, *fast=head;
    int i;

    for(i=0; i<pos && fast != null; i++){
        fast = fast->next;
    }
    
    if(fast == null && i == pos){
        return head->key;
    }

    if(fast == null){
        return INT_MIN;
    }

    while (fast != null )
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow->key;
    

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
    cout << "Enter the position: ";
    int pos;
    cin >> pos;
    printList(head);

    cout << "Middle of the list is: "<<nthEndList(head, pos)<<'\n';
    




    return 0;
}