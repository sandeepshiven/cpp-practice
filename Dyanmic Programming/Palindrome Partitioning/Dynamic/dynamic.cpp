#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){

   
    if(i == j){
        return true;
    }
    
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palParts(string s, int n){

    vector<vector<int>>dp(n, vector<int>(n));
    for(int i=0; i<n; i++){
        dp[i][i] = 0;
    }
    for(int gap=1; gap<n; gap++){
        for(int i=0; i+gap<n; i++){
            int j = i+gap;
            if(isPalindrome(s, i, j)){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = INT_MAX;
                for(int k=i; k<j; k++){
                    dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    return dp[0][n-1];
}

int main(){

    int n; 
    string s; 
    cout << "Enter the string: ";   
    cin >> s;
    n = s.length();
    cout << "Min cuts: " << palParts(s, n) << '\n';
   

   return 0;
}