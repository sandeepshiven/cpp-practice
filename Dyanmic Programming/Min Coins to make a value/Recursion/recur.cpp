#include <bits/stdc++.h>
using namespace std;



int minCoins(vector<int>&arr, int val, int n){

    if(val == 0){
        return 0;
    }
    int res = INT_MAX;
    for(int i=0; i<n; i++){
        if(arr[i] <= val){
            int sub_res = minCoins(arr, val-arr[i], n);
            if(sub_res != -1){
                res = min(res, sub_res+1);
            }
        }
    }
    return res;
    
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