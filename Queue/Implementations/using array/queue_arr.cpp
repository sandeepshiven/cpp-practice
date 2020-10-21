#include<bits/stdc++.h>

using namespace std;


class MyQueue{

    private:
        int size;
        int front;
        int cap;
        int *arr;
    

    public:
        MyQueue(int);
        void enqueue(int);
        int dequeue();
        int getSize();
        int getFrontIndex();
        int getRearIndex();
        bool isFull();
        bool isEmpty();

};

MyQueue::MyQueue(int n){

    cap = n;
    arr = new int[cap];
    front = 0;
    size = 0;

}

void MyQueue::enqueue(int x){
    
    if(isFull()){
        return;
    }
    int rear = getRearIndex();
    rear = (rear+1)%cap;
    arr[rear] = x;
    size++;
}

int MyQueue::dequeue(){

    if(isEmpty()){
        return;
    }
    int x = front;
    front = (front +1)%cap;
    size--;
    return arr[x];
}

int MyQueue::getRearIndex(){
    if(isEmpty()){
        return -1;
    }
    else{
        return (front+size-1)%cap;
    }

}

int MyQueue::getFrontIndex(){
    if(isEmpty()){
        return -1;
    }
    else{
        return front;
    }
}

bool MyQueue::isEmpty(){
    return size==0;
}

bool MyQueue::isFull(){
    return size==cap;
}


int main(){

    return 0;
}