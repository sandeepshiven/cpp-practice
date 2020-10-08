#include<bits/stdc++.h>

using namespace std;

class MyStack{
    private:
        int *arr;
        int cap;
        int top;
    
    public:
        MyStack(int);
        void push(int);
        int pop();
        int peek();
        int size();
        bool isEmpty();
};

MyStack::MyStack(int s){
    cap = s;
    arr = new int[cap];
    top = -1;
}

void MyStack::push(int ele){
    arr[++top] = ele;
}

int MyStack::pop(){
    return arr[top--];
}

int MyStack::peek(){
    return arr[top];
}

int MyStack::size(){
    return top+1;
}

bool MyStack::isEmpty(){
    return (top == -1);
}



int main(){

    MyStack myStack(5);
    myStack.push(5);
    myStack.push(10);
    myStack.push(20);
    cout << myStack.pop()<<'\n';
    cout << myStack.size()<<'\n';
    cout << myStack.peek()<< '\n';
    cout << myStack.isEmpty() << '\n';


    return 0;
}