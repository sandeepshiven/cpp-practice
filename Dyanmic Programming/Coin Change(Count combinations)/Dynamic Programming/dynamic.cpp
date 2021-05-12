#include <bits/stdc++.h>
using namespace std;

int  findSum(vector<int>&coins, int sum, int n){

    vector<vector<int>>dp(sum+1, vector<int>(n+1, 0));
    
    for(int i=0; i<=n; i++){
        dp[0][i] = 1;
    }
    for(int i=1; i<= sum; i++){
        for(int j=1; j<=n; j++){
            dp[i][j] = dp[i][j-1];
            if(coins[j-1] <= i){
                dp[i][j] += dp[i - coins[j-1]][j];
            }
        }
    }
    return dp[sum][n];
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