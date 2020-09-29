
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

Node *seperateEvenOdd(Node *head){

    Node *even_head=null,*odd_head = null, *curr=head;

    while (curr != null){

        Node *prev = curr;

        if(curr->key%2 == 0){
            even_head = insertEnd(even_head, curr->key);
        }
        else{
            odd_head = insertEnd(odd_head, curr->key);
        }
        curr = curr->next;
        delete(prev);
    }

    if(even_head != null && odd_head == null){
        return even_head;

    }
    else if(odd_head != null && even_head == null){
        return odd_head;
    }
    else{
        head = even_head;
        while (even_head->next != null)
        {
            even_head = even_head->next;
        }
        even_head->next = odd_head;
        return head;
        
    }
    
    

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

    
    
    
    

    //head = reverseList(head, k);

    printList(head);

    head = seperateEvenOdd(head);
    
    printList(head);
    




    return 0;
}