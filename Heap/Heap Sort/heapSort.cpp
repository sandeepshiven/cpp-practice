#include<bits/stdc++.h>

using namespace std;




void maxHeapify(vector<int>&arr, int n, int i){
    int lt = (2*i) + 1;
    int rt = (2*i) + 2;
    int gr = i;
    
    if(lt < n && arr[i] < arr[lt]){
        gr = lt;
    }
    if(rt < n && arr[gr] < arr[rt]){
        gr = rt;
    }
    if(gr != i){
        swap(arr[i], arr[gr]);
        maxHeapify(arr, n, gr);
    }
}

void buildHeap(vector<int>&arr, int n){
    for(int i=(n-2)/2; i>=0; i--){
        maxHeapify(arr, n, i);
    }
}

void heapSort(vector<int>&arr, int n){
    buildHeap(arr, n);
    for(int i=n-1; i>=1; i--){
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}


int main(){
    
    int n;
    cout << "Enter the size of the arr: ";
    cin >> n;
    cout << "Enter the elements of the arr: ";
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    heapSort(arr, n);

    for(auto i: arr){
        cout << i << " "; 
    }
    cout << '\n';
    

    return 0;


}



