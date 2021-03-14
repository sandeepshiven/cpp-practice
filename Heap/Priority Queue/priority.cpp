#include<bits/stdc++.h>

using namespace std;

struct Person{
    int age;
    float ht;
    Person(int a, float h){
        age = a;
        ht = h;
    }
};

struct myComp{
    bool operator()(Person const &p1, Person const &p2){
        p1.ht < p2.ht;
    }
};

int main(){

    priority_queue<int>pq; // max heap
    //priority_queue<int, vector<int>, greater<int>>pq; // min heap
    pq.push(10);
    pq.push(15);
    pq.push(5);
    cout << pq.size()<<" ";
    cout << pq.top() << " ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';

    priority_queue<Person, vector<Person>, myComp>pq;

    return 0;
}
















