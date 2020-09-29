
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

void makeLoop(Node *head, int k){

    Node *curr = head;
    int count = 1;
    if(k <1){
        return;
    }

    while(curr != null && count<k){
        curr = curr->next;
        count++;
    }
    Node *rest = curr;
    while (rest->next != null)
    {
        rest = rest->next;

    }
    rest->next = curr;
    

}


void printList(Node *head){
    //Node *curr = head;
    int count =0;
    while(head != null && count < 100){
        cout << head->key << "->";
        head = head->next;
        count++;
    }
    cout << "END\n";

}

bool detectLoop(Node *head){

    Node *dummy = new Node(0);

    Node *curr = null;

    while(head->next != null)
    {
        curr = head->next;
        head->next = dummy;
        head = curr;
        if(curr == dummy){
            return true;
        }
    }
    
    return false;

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

    cout << "Enter nth node number for looping: ";
    int k;
    cin >> k;
    makeLoop(head, k); 
    
    

    //head = reverseList(head, k);

    printList(head);
    if(detectLoop(head)){
        cout <<"Yes\n";
    }
    else{
        cout << "No\n";
    }
    




    return 0;
}