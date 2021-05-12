#include <bits/stdc++.h>
using namespace std;

int fillSack(vector<pair<int, int>>&arr, int n, int w){

    vector<vector<int>>dp(n+1, vector<int>(w+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            if(arr[i-1].second > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j], arr[i-1].first + dp[i-1][j - arr[i-1].second]);
            }
        }
    }
    return dp[n][w];
}


int main(){

    int n, w;
    
    cout << "Enter number of items: ";
    cin >> n;
    vector<pair<int, int>>arr(n);
    for(int i=0; i<n; i++){
        cout << "Enter value and weight of item" << i+1 << ": "; 
        cin >> arr[i].first >> arr[i].second;
    }

    cout << "Enter max weight: ";
    cin >> w;
   
    
    cout << "Result: " << fillSack(arr, n, w) << '\n';

    return 0;
}