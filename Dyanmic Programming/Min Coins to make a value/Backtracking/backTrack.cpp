#include <bits/stdc++.h>
using namespace std;

void minCoinHelper(vector<int>&arr, int val, int n, int &res, int index, int sz){

    if(index >=n || val < 0){
        return;
    }
    if(val == 0){
        res =  min(res, sz);
    }
    else{
        sz++;
        minCoinHelper(arr, val-arr[index], n, res, index, sz);
        sz--;
        minCoinHelper(arr, val, n, res, index+1, sz);
        
    }

}

int minCoins(vector<int>&arr, int val, int n){

    sort(arr.begin(), arr.end());
    int res = INT_MAX;
    
    minCoinHelper(arr, val, n, res, 0, 0);
    return res == INT_MAX? -1: res;

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