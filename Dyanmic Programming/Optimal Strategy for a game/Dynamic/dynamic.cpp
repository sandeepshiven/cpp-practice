#include <bits/stdc++.h>
using namespace std;

int sol(vector<int>&arr, int n){

    vector<vector<int>>dp(n, vector<int>(n));
    for(int i=0; i<n-1; i++){
        dp[i][i+1] = max(arr[i], arr[i+1]);
    }

    for(int gap = 3; gap <n; gap += 2){
        for(int i=0; i+gap<n; i++){
            int j = i+gap;
            dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]), 
                            arr[j] + min(dp[i+1][j-1], dp[i][j-2]));
        }
    }
    return dp[0][n-1];

}

int main(){

    int n;
    cout << "Enter the no. of items: ";
    cin >> n;
    cout << "Enter the items: ";
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Player 1 score: " << sol(arr, n);
    cout << '\n';

    return 0;
}