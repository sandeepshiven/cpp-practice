#include<bits/stdc++.h>

using namespace std;

class MyDeque{

    private:
        int *arr, front, size, cap;
    
    public:
        MyDeque(int);
        void insertFront(int);
        void insertRear(int);
        void deleteFront();
        void deleteRear();
        int getRear();
        int getFront();
        bool isEmpty();
        bool isFull();


};

MyDeque::MyDeque(int c){

    arr = new int[c];
    cap = c;
    front = 0;
    size = 0;
}

void MyDeque::insertFront(int x){
    if(isFull()){
        return;
    }
    front = (front-1+cap)%cap;
    arr[front] = x;
    size++;
}

void MyDeque::insertRear(int x){
    if(isFull()){
        return;
    }
    int rear = getRear();
    rear = (rear+1)%cap;
    arr[rear] = x;
    size++;
}

void MyDeque::deleteFront(){
    if(isEmpty()){
        return;
    }
    front = (front + 1)%cap;
    size--;

}

void MyDeque::deleteRear(){
    if(isEmpty()){
        return;
    }
    size--; 
}

int MyDeque::getFront(){
    if(isEmpty()){
        return -1;
    }
    return front;
}

int MyDeque::getRear(){
    if(isEmpty()){
        return -1;
    }
    return (fornt+size-1)%cap;
}


int main(){

    return 0;
}