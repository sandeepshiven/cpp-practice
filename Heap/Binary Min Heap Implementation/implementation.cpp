#include<bits/stdc++.h>

using namespace std;

class MinHeap{
    private:
        int *arr;
        int size;
        int capacity;
        int left(int i);
        int right(int i);
        int parent(int i);
        void heapify(int i);        

    public:
        MinHeap(int c);
        void insert(int data);
        int extractMin();
        void decreaseKey(int i, int data);
        void deleteKey(int i);
        int getMin();
        void buildHeap(int in[]);



};

void MinHeap::buildHeap(int in[]){
    size = capacity;
    for(int i=0; i<capacity; i++){
        arr[i] = in[i];
    }
    for(int i=(size-2)/2; i>=0; i--){
        heapify(i);
    }

}

int MinHeap::getMin(){
    if(size == 0){ 
        return INT_MAX;
    }
    return arr[0];
}
void MinHeap::deleteKey(int i){
    decreaseKey(i, INT_MIN);
    extractMin();
}
MinHeap::MinHeap(int c){
    arr = new int[c];
    size = 0;
    capacity = c;
}
       
void MinHeap::insert(int data){
    if(size < capacity){
        arr[size++] = data;
        for(int i=size-1; i>=0 && arr[parent(i)] > arr[i]; ){
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
}



int MinHeap::left(int i){
    return ((2*i)+1);
}
int MinHeap::right(int i){
    return ((2*i)+2);
}
int MinHeap::parent(int i){
    return ((i-1)/2);
}
        
void MinHeap::heapify(int i){

    int lt = left(i), rt = right(i);
    int sm = i;
    
    if(lt < size && arr[i] > arr[lt]){
        sm = lt;
    }
    if(rt < size && arr[sm] > arr[rt]){
        sm = rt;
    }
    if(sm != i){
        swap(arr[sm], arr[i]);
        heapify(sm);
    }
}

int MinHeap::extractMin(){
    if(size == 0){
        return INT_MAX;
    }
    if(size == 1){
        size--;
        return arr[0];
    } 
    swap(arr[0], arr[size-1]);
    size--;
    heapify(0);
    
    return arr[size];

}


void MinHeap::decreaseKey(int i, int data){
    arr[i] = data;
    while(i != 0 && arr[parent(i)] > arr[i]){
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }    
    
}

int main(){

    return 0;
}
















