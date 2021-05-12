#include <bits/stdc++.h>
using namespace std;

pair<int, string> lcs(string s1, string s2){

    int m = s1.length();
    int n = s2.length();

    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string s="";
    int i=m, j=n;
    while(i>= 1 && j >= 1){
        if(s1[i-1] == s2[j-1]){
            s += s1[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] >= dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(s.begin(), s.end());
    return {dp[m][n], s};
    
}


int main(){

    string s1, s2;

    cout << "Enter string1: ";
    cin >> s1;
    cout << "Enter string2: ";
    cin >> s2;
    pair<int, string>res = lcs(s1, s2);
    cout << "Longest common subsequence length: " << res.first <<'\n';
    cout << "The subsequence is: " << res.second << '\n';

    return 0;
}