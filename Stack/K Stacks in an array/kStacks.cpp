#include<bits/stdc++.h>

using namespace std;

class kStacks{

    private:
        int *arr, *top,*next;
        int cap, freetop, K;

    public:
        kStacks(int , int);
        void push(int, int);
        int pop(int);
};

kStacks::kStacks(int k, int n){
    K = k;
    cap = n;
    arr = new int[n];
    top = new int[k];
    next = new int[n];
    freetop = 0;

    for(int i=0; i<K; i++){
        top[i] = -1;
    }

    for(int i=0; i<cap-1; i++){
        next[i] = i+1;
    }
    next[cap-1] = -1;
}


void kStacks::push(int x, int sn){

    int i = freetop;
    freetop = next[i];
    next[i] = top[sn];
    top[sn] = i;
    arr[i] = x;

}

int kStacks::pop(int sn){

    int i = top[sn];
    top[sn] = next[i];
    next[i] = freetop;
    freetop = i;
    return arr[i];
    
}
















int main(){

    return 0;
}