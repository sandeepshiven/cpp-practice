

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



void makeIntersection(Node *list1, Node *list2, int n){

    if(n == 0){
        return;
    }

    while (list2->next != null)
    {
        list2 = list2->next;
    }

    n--;
    while(n--){
        list1 = list1->next;
    }
    list2->next = list1;

}


Node *mergeList(Node *list1, Node *list2){

    Node *head1 = list1, *head2 = list2;

    if(head1 == null){
        return head2;
    }
    if(head2 == null){
        return head1;
    }
    
    Node *head = null, *prev = null;

    if(head1->key > head2->key){
        head = head2;
        prev = head2;
        head2 = head2->next;
    }
    else{
        head = head1;
        prev = head1;
        head1 = head1->next;
        
    }
    
    

    while(head1 != null && head2 != null){

        if(head1->key < head2->key){
            prev->next = head1;
            head1 = head1->next;
        }
        else{
            prev->next = head2;
            head2 = head2->next;
        }
        prev = prev->next;

    }
    if(head1 == null){
        prev->next = head2;
        
    }
    if(head2 == null){
        prev->next = head1;
    }
    return head;

    

}

int main(){

    Node *list1 = NULL;
    

    cout << "How many nodes you want in List-1? : ";
    int n, temp;
    cin >>n;
    cout<< "Insert "<<n<<" nodes of List-1: ";
    while(n--){
        cin >>temp;
        list1 = insertEnd(list1, temp);
    }

    Node *list2 = NULL;
    

    cout << "How many nodes you want in List-2? : ";
    
    cin >>n;
    cout<< "Insert "<<n<<" nodes of List-2: ";
    while(n--){
        cin >>temp;
        list2 = insertEnd(list2, temp);
    }
    
    
    printList(list1);
    printList(list2);

    list1 = mergeList(list1, list2);

    printList(list1);

    
    return 0;
}