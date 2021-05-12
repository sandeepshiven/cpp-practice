#include <bits/stdc++.h>
using namespace std;

int  findSum(vector<int>&coins, int sum, int n){

    vector<int>dp(sum+1, 0);
    dp[0] = 1;
    
    for(int i=0; i<n; i++){
        for(int j=1; j<=sum; j++){
            if(coins[i] <= j){
                dp[j] += dp[j-coins[i]];
            }
        }
    }

    return dp[sum];
}

int main(){
    
    int n, sum;
    cout << "Enter the number of Coins: ";
    cin >> n;
    cout << "Enter the values of coins: ";
    vector<int>coins(n);
    for(int i=0; i<n; i++){
        cin >> coins[i];
    }
    cout << "Enter the sum you want: ";
    cin >> sum;
    sort(coins.begin(), coins.end());
    vector<vector<int>>res;
    vector<int>nums;
    cout << findSum(coins, sum, n);
    cout << "\n";
    
    return 0;
}