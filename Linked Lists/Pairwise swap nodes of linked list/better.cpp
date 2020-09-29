

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
    int count =0;
    while(head != null ){
        cout << head->key << "->";
        head = head->next;
        count++;
    }
    cout << "END\n";

}



Node *pairWiseSwap(Node *head){

    if(head == null || head->next==null){
        return head;
    }

    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    
    while (curr != null && curr->next != null)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }

    prev->next = curr;
    
    
    return head;

    

}

int main(){

    Node *head = NULL;
    

    cout << "How many nodes you want in List-1? : ";
    int n, temp;
    cin >>n;
    cout<< "Insert "<<n<<" nodes of List-1: ";
    while(n--){
        cin >>temp;
        head = insertEnd(head, temp);
    }
    printList(head);
    head = pairWiseSwap(head);
    printList(head);
   

    return 0;
}