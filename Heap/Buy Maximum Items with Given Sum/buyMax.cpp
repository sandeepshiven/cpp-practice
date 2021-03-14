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
    cout << "Enter the sum: ";
    int sum;
    cin >> sum;
    priority_queue<int, vector<int>, greater<int>>pq(arr.begin(), arr.end());

    
    int res=0, currSum=0;
    while(!pq.empty() && currSum < sum){
        
        currSum += pq.top();
        if(currSum <= sum){
            res++;
        }
        pq.pop();
    }

    cout << res;
    

    cout << '\n';








    return 0;
}