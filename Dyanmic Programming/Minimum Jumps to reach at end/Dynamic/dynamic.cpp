#include <bits/stdc++.h>
using namespace std;


int minJumps(vector<int>&jumps, int n){

    vector<int>dp(n, INT_MAX);
    dp[0] = 0;
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(jumps[j]+j >= i){
                if(dp[j] != INT_MAX){
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
    }
    return dp[n-1];
}


int main(){

    int n;
    cout << "Enter no. of jumps: ";
    cin >> n;
    vector<int>jumps(n);
    cout << "Enter jumps: ";
    for(int i=0; i<n; i++){
        cin >> jumps[i];
    }
    cout << "Min jumps: " << minJumps(jumps, n) << '\n';

    return 0;
}