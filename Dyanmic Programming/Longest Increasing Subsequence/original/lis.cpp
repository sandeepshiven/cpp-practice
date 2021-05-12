#include <bits/stdc++.h>
using namespace std;


int lis(vector<int>&arr, int n){

    vector<int>dp(n, 0);
    int maxIncrease=0;
    for(int i=0; i<n; i++){
        dp[i] = 1;
        maxIncrease =0;
        for(int j=i-1; j>=0; j--){
            if(arr[j] < arr[i]){
                if(dp[j] > maxIncrease){
                    maxIncrease = dp[j];
                }               
            }
        }
        dp[i] += maxIncrease;
    }
    return *max_element(dp.begin(), dp.end());
}


int main(){


    int n; 
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "LIS length: "<< lis(arr, n)<< '\n';

    return 0;
}