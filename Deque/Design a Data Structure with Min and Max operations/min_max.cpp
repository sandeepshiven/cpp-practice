#include<bits/stdc++.h>

using namespace std;


class MyDS{
    private:
        deque<int>dq;
    public:
        void insertMin(int x);
        void insertMax(int x);
        int getMin();
        int getMax();
        int extractMin();
        int extractMax();
};

void MyDS::insertMin(int x){
    dq.push_front(x);
}

void MyDS::insertMax(int x){
    dq.push_back(x);
}

int MyDS::getMin(){
    return dq.front();
}

int MyDS::getMax(){
    return dq.back();
}


int MyDS::extractMin(){
    return dq.pop_front();
}

int MyDS::extractMax(){
    return dq.pop_back();
}


int main(){

    return 0;
}