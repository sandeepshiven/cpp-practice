#include<bits/stdc++.h>

using namespace std;

class Node{

    public:
        int data;
        Node *next;
        Node(int x){
            data = x;
            next = NULL;
        }

};

class MyQueue{
    
    private:
        int size;
        Node *front;
        Node *rear;
    
    public:
        MyQueue();
        void enqueue(int);
        int dequeue();
        int getSize();
        bool isEmpty();
        int getFront();
        int getRear();


};

MyQueue::MyQueue(){

    size=0;
    front = rear = NULL;
}

void MyQueue::enqueue(int x){
    if(front==NULL){
        front = new Node(x);
        rear = front;
        size++;
    }
    else{
        rear->next = new Node(x);
        rear = rear->next;
        size++; 
    }
}

int MyQueue::dequeue(){
    if(front==NULL){
        return INT_MIN;
    }
    int x = front->data;
    Node *poped = front;
    front = front->next;
    if(front == NULL){
        rear = NULL;
    }
    delete(poped);
    size--;
    return x;
    
}

bool MyQueue::isEmpty(){
    return size;
}

int MyQueue::getFront(){
    return front->data;

}

int MyQueue::getRear(){
    return rear->data;

}

int MyQueue::getSize(){
    return size;
}

int main(){

    

    return 0;
}