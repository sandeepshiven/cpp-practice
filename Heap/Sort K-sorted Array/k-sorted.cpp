#include<bits/stdc++.h>

using namespace std;



int main(){

    /*
    An element at index i will be present between
    the indexes i-k to i+k in the sorted array
    */

    cout << "Enter the size of the array: ";
    int n;
    cin >>n;
    cout << "Enter the elements of the array: ";
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    int k;
    cin >> k;
    priority_queue<int, vector<int>, greater<int>>pq;

    for(int i=0; i<=k; i++){
        pq.push(arr[i]);
    }
    int index=0;
    for(int i=k+1; i<n; i++){
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()){
        arr[index++] = pq.top();
        pq.pop();
    }

    for(auto i: arr){
        cout << i << " ";
    }
    cout << '\n';








    return 0;
}