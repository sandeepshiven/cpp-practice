#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>&arr, int n, int sum){

    vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
    for(int i=0; i<=n; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(j < arr[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]]; 
            }
        }
    }
    return dp[n][sum];
}

int main(){

    int n;
    cout << "Enter the size of array: ";
    cin >> n; 
    cout << "Enter the elements of array: ";
    vector<int>arr(n);

    for(int i=0; i< n; i++){
        cin >> arr[i];
    }
    cout << "Enter the sum: ";
    int sum;
    cin >> sum;
    cout << "Total subsets are: " << countSubsets(arr, n, sum)<< '\n';


    return 0;
}