#include<bits/stdc++.h>

using namespace std;

class MyStack{
    private:
        vector<int>vec;
    
    public:
        
        void push(int);
        int pop();
        int peek();
        int size();
        bool isEmpty();
};


void MyStack::push(int ele){
    vec.push_back(ele);
}

int MyStack::pop(){
    int res = vec.back();
    vec.pop_back();
    return res;
}

int MyStack::peek(){
    return vec.back();
}

int MyStack::size(){
    return vec.size();
}

bool MyStack::isEmpty(){
    return vec.empty();
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