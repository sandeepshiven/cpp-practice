

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


Node *findIntersection(Node *list1, Node *list2){

    unordered_set<Node *>nodeSet;

    while(list1 != null)
    {
        nodeSet.insert(list1);
        list1 = list1->next;
    }
    
    bool intersectPresent = false;

    while(list2 != null){

        if(nodeSet.find(list2) != nodeSet.end()){
            return list2;
        }
        list2 = list2->next;
    }

    return (new Node(INT_MIN));
    

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
    cout <<"------------Before Intersection----------------\n";
    
    printList(list1);
    printList(list2);

    cout<<"Enter the nth node you want common: ";
    cin >> n;
    makeIntersection(list1, list2, n);

    cout <<"------------After Intersection----------------\n";

    printList(list1);
    printList(list2);

    cout << "The intersection Node is: "<<findIntersection(list1, list2)->key<<'\n';
    




    return 0;
}