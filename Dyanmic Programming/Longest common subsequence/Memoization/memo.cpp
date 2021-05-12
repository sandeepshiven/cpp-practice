#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, vector<vector<int>>&dp,int m, int n){

    if(dp[m][n] != -1){
        return dp[m][n];
    }
    if(m==0 || n==0){
        dp[m][n] = 0;
    }
    else{
        if(s1[m-1] == s2[n-1]){
            dp[m][n] = (1 + lcs(s1, s2, dp, m-1, n-1)); 
        }
        else{
            dp[m][n] = max(lcs(s1, s2, dp, m-1, n), lcs(s1, s2, dp, m, n-1));
        }
    }
    return dp[m][n];
}


int main(){

    string s1, s2;

    cout << "Enter string1: ";
    cin >> s1;
    cout << "Enter string2: ";
    cin >> s2;
    vector<vector<int>>dp(s1.length()+1, vector<int>(s2.length()+1, -1));
    cout << "Longest common subsequence length: " << lcs(s1, s2, dp, s1.length(), s2.length())<<'\n';

    return 0;
}