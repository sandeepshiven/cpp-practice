
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

Node * reverseList(Node *head, int k){

    Node *curr = head, *prevFirst = null;
    bool firstPass = true;

    while (curr != null)
    {  
    
        Node *first = curr,*prev=null;
        int count = 0;
        while(curr != null && count < k){
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if(firstPass){
            head = prev;
            firstPass = false;
        }
        else{
            prevFirst->next = prev;
        }
        prevFirst = first;
    }
    return head;

    

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

    cout << "Enter the size of k: ";
    int k;
    cin >> k; 
    
    printList(head);

    head = reverseList(head, k);

    printList(head);
    




    return 0;
}