#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int>&arr, int n){

    
    if(n==0){
        return -1;
    }
    else if(n==1){
        return arr[0];
    }
    else{
        int prev_prev = arr[0];
        int prev = max(arr[0], arr[1]);
        int res = prev;
        for(int i=3; i<=n; i++){
            res = max(prev, arr[i-1]+ prev_prev);
            prev_prev = prev;
            prev = res;
        }
        return res;
    } 

}

int main(){

    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Max Sum: " << maxSum(arr, n) << '\n';

    return 0;
}