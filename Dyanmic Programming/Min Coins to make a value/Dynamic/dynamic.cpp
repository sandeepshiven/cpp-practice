#include <bits/stdc++.h>
using namespace std;



int minCoins(vector<int>&arr, int val, int n){

    vector<int>dp(val+1);
    dp[0] = 0;
    for(int i=1; i<=val; i++){
        dp[i] = INT_MAX;
        for(int j=0; j<i; j++){
            if(arr[j] <= i){
                int sub_res = dp[i-arr[j]];
                if(sub_res != INT_MAX){
                    dp[i] = min(dp[i], sub_res+1);
                }
            
            }
        }
    }
    return dp[val];
}

int main(){

    int n;
    cout << "Enter number of coins: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter coins: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Enter value: ";
    int val;
    cin >> val;

    cout << "Min Coins: " << minCoins(arr, val, n)<<'\n';

    return 0;
} 