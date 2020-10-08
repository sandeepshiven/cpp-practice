#include<bits/stdc++.h>

using namespace std;


class Node{
    public:
        int data;
        Node *next;
        Node(int d){
            data = d;
            next = NULL;
        }
};



class MyStack{
    private:
        Node *head;
        int sz;
    
    public:
        MyStack();
        void push(int);
        int pop();
        int peek();
        int size();
        bool isEmpty();
};

MyStack::MyStack(){
    head = NULL;
    sz = 0;
}

void MyStack::push(int ele){
    Node *temp = new Node(ele);
    temp->next = head;
    head = temp;
    sz++; 
}

int MyStack::pop(){
    if(head == NULL){
        return INT_MAX;
    }
    int res = head->data;
    Node *temp = head;
    head = head->next;
    delete(temp);
    sz--;
    return res;
    
    return res;
}

int MyStack::peek(){
    return head->data;
}

int MyStack::size(){
    return sz;
}

bool MyStack::isEmpty(){
    return (sz==0);
}



int main(){

    MyStack myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(20);
    cout << myStack.pop()<<'\n';
    cout << myStack.size()<<'\n';
    cout << myStack.peek()<< '\n';
    cout << myStack.isEmpty() << '\n';


    return 0;
}