#include <bits/stdc++.h>
using namespace std;

int  findSum(vector<int>&coins, int sum, int n){

    if(sum == 0){
        return 1;
    }
    if(n == 0){
        return 0;
    }
    int res = findSum(coins, sum, n-1);
    if(coins[n-1] <= sum){
        res += findSum(coins, sum - coins[n-1], n);
    }
    return res;
    
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
    
    vector<vector<int>>res;
    vector<int>nums;
    cout << findSum(coins, sum, n) << '\n';

    
    return 0;
}