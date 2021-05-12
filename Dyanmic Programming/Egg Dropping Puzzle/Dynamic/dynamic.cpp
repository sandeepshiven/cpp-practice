#include <bits/stdc++.h>
using namespace std;


int eggDrop(int f, int e){

    vector<vector<int>>dp(f+1, vector<int>(e+1));

    for(int i=1; i<e; i++){
        dp[0][i] = 0;
        if(f > 1){
            dp[1][i] = 1;
        }
    }
    for(int i=1; i<=f; i++){
        dp[i][1]  = i;
    }

    for(int i=2; i<=f; i++){
        for(int j = 2; j<=e; j++){
            dp[i][j] = INT_MAX;
            for(int x=1; x<=i; x++){
                dp[i][j] = min(dp[i][j], 1+max(dp[x-1][j-1], dp[i-x][j]));
            }
        }
    }
    return dp[f][e];
   
}


int main(){

    int e, f;
    cout << "Enter number of eggs: ";
    cin >>e;
    cout << "Enter number of floors: ";
    cin >>f;
    cout << "Min. trials: " << eggDrop(f, e) << '\n';

    return 0;
}