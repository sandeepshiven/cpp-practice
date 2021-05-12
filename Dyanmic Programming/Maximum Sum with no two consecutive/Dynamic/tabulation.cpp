#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int>&arr, int n){

    vector<int>dp(n+1);
    if(n==0){
        return -1;
    }
    else if(n==1){
        return arr[0];
    }
    else{
        dp[1] = arr[0];
        dp[2] = max(arr[0], arr[1]);
        for(int i=3; i<=n; i++){
            dp[i] = max(dp[i-1], arr[i-1]+dp[i-2]);
        }
        return dp[n];
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