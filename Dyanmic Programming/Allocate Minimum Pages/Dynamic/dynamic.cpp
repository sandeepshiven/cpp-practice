#include <bits/stdc++.h>
using namespace std;

int sum(vector<int>&arr, int i, int j){
    int res = 0;
    while(i<=j){
        res += arr[i];
        i++;
    }
    return res;
}

int minPages(vector<int>&arr, int n, int k){

    vector<vector<int>>dp(k+1, vector<int>(n+1));

    for(int i=1; i<=n; i++){
        dp[1][i] = sum(arr, 0, i-1);
    }
    for(int i=1; i<=k; i++){
        dp[i][1] = arr[0];
    }
    for(int i=2; i<=k; i++){
        for(int j=2; j<=n; j++){
            int res = INT_MAX;
            for(int p=1; p<j; p++){
                res = min(res, max(dp[i-1][p], sum(arr, p, j-1)));
            }
            dp[i][j] = res;
        }
    }
    return dp[k][n];
  
}

int main(){

    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the pages in book: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Enter the number of students: ";
    int k;
    cin >> k;
    cout << "Min no. of pages read by a student is: " << minPages(arr, n, k)<<'\n';

    return 0;
}