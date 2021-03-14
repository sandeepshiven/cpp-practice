#include<bits/stdc++.h>

using namespace std;




int main(){

    /*
    An element at index i will be present between
    the indexes i-k to i+k in the sorted array
    */

    cout << "Enter the size of the array: ";
    int n, k, x;
    cin >>n;
    cout << "Enter the elements of the array: ";
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Enter the value of x: ";
    cin >> x;
    cout << "Enter the value of k: ";
    cin >> k;
    priority_queue<pair<int,int>>pq;

    for(int i=0; i<k; i++){
        pq.push(make_pair(abs(arr[i]-x), arr[i]));
    }
    int index=0;
    for(int i=k; i<n; i++){
        if(abs(arr[i]-x) <= pq.top().first){
            pq.pop();
            pq.push(make_pair(abs(arr[i]-x), arr[i]));
        }
    }
	while(!pq.empty()){
		cout << pq.top().second<<" ";
		pq.pop();
	}
    cout << '\n';








    return 0;
}