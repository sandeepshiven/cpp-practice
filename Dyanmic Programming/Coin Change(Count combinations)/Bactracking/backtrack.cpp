#include <bits/stdc++.h>
using namespace std;

void findSum(vector<int>&coins, vector<vector<int>>&res, vector<int>&nums, int sum, int index, int n){

    if(index>=n || sum <0){
        return;
    }
    if(sum == 0){
        res.push_back(nums);
    }
    else{
        nums.push_back(coins[index]);
        findSum(coins, res, nums, sum-coins[index], index, n);
        nums.pop_back();
        findSum(coins, res, nums, sum, index+1, n);
    }
    
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
    findSum(coins, res, nums, sum, 0, n);

    for(auto i: res){
        for(auto j: i){
            cout << j << " ";
        }
        cout << '\n';
    }

    return 0;
}