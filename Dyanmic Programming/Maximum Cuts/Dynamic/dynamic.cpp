#include <bits/stdc++.h>
using namespace std;


int maxCut(int n, int a, int b, int c){

    vector<int>dp(n+1);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = -1;
        if(i-a >= 0){
            dp[i] = max(dp[i], dp[i-a]);
        }
        if(i-b >= 0){
            dp[i] = max(dp[i], dp[i-b]);
        }
        if(i-c >= 0){
            dp[i] = max(dp[i], dp[i-c]);
        }
        if(dp[i] != -1){
            dp[i]++;
        }
    }
    
    return dp[n];
}

int main(){

    int n, a, b, c;
    cout << "Enter the size of rod: ";
    cin >> n;
    cout << "Enter values of a, b and c: ";
    cin >> a >> b >> c;
    cout<< maxCut(n, a, b, c) << '\n';

    return 0;
}