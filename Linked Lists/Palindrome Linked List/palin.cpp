

#include<bits/stdc++.h>

using namespace std;

#define null NULL

struct Node{

    char key;
    Node *next;
    Node(char x){
        key = x;
        next = null;
    }

};

Node *insertEnd(Node *head, char key){

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


Node *findMiddle(Node *head){


    Node *slow=head, *fast=head;

    while (fast->next != null && fast->next->next != null)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node * reverseList(Node *head){
    
    Node *curr = head,*prev=null, *next = null;
    while(curr != null){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }
    return prev;

    

}

bool isPalindrome(Node *head){

    Node *middle = findMiddle(head);
    middle->next = reverseList(middle->next);
    middle = middle->next;


    while(middle != null){
        if(middle->key != head->key){
            return false;
        }
        middle = middle->next;
        head = head->next; 
    }


   
    return true;
}

int main(){

    Node *list1 = NULL;
    

    cout << "How many nodes you want in List-1? : ";
    int n;
    char temp;
    cin >>n;
    cout<< "Insert "<<n<<" nodes of List-1: ";
    while(n--){
        cin >>temp;
        list1 = insertEnd(list1, temp);
    }

   
    
    
    printList(list1);
    

    if(isPalindrome(list1)){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }

    
    return 0;
}