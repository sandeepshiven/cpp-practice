

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

    Node *even_start=null,*odd_start = null,*even_end=null,*odd_end = null, *curr=head;

    while (curr != null){

        int x = curr->key;

        if(x%2 == 0){
            if(even_start == null){
                even_start = curr;
                even_end = even_start;
            }
            else{
                even_end->next = curr;
                even_end = even_end->next;
            }
        }
        else{
            if(odd_start == null){
                odd_start = curr;
                odd_end = odd_start;
            }
            else{
                odd_end->next = curr;
                odd_end = odd_end->next;
            }
            
        }
        curr = curr->next;
    }

    if(even_start == null || odd_start == null){
        return head;
    }
    even_end->next = odd_start;
    odd_end->next = null;
    return even_start;
    
    

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