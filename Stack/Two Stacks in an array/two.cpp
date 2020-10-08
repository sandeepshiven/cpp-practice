#include<bits/stdc++.h>

using namespace std;

class TwoStacks{
    private:
        int *arr;
        int cap;
        int top1;
        int top2;

    public:
        TwoStacks(int);
        void push1(int);
        void push2(int);
        int pop1();
        int pop2();
        int top_1();
        int top_2();
        int size1();
        int size2();
};

TwoStacks::TwoStacks(int s){
    cap = s;
    top1 = -1;
    top2 = cap;
    arr = new int[s];
}

void TwoStacks::push1(int data){

    if(top1<top2-1){
        arr[++top1] = data;
    }
    else{
        cout << "Overflow\n";
    }

}


void TwoStacks::push2(int data){

    if(top2-1>top1){
        arr[--top2] = data;
    }
    else{
        cout << "Overflow\n";
    }

}

int TwoStacks::pop1(){

    if(top1 > -1){
        return arr[top1--];
    }
    else{
        cout << "Underflow\n";
        return 0;
    }

}

int TwoStacks::pop2(){

    if(top2 < cap){
        return arr[top2++];
    }
    else{
        cout << "Underflow\n";
        return 0;
    }

}

int TwoStacks::size1(){
    if(top1>-1){
        return top1+1;
    }
    else{
        return 0;
    }
}

int TwoStacks::size2(){
    if(top2<cap){
        return cap-top2;
    }
    else{
        return 0;
    }
}

int TwoStacks::top_1(){
    if(top1>-1){
        return arr[top1];
    }
    else{
        return INT_MIN;
    }
    
}

int TwoStacks::size2(){
    if(top2<cap){
        return arr[top2];
    }
    else{
        return INT_MIN;
    }
}



int main(){

    return 0;
}