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


void printList(Node *head){
    //Node *curr = head;
    while(head != NULL){
        cout << head->key << "->";
        head = head->next;
    }
    cout << "END\n";

}

int middleList(Node *head){
    int num=0;
    Node *curr = head;
    while(curr != NULL)
    {
        num++;
        curr = curr->next;
    }
    curr = head;
    for(int i=0; i<(num/2); i++){
        curr = curr->next;
    }
    return curr->key;

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

    cout << "Middle of the list is: "<<middleList(head)<<'\n';
    




    return 0;
}