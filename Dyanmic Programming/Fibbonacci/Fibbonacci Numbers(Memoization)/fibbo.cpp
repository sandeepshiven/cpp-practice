#include <bits/stdc++.h>
using namespace std;

long long int fib(int n, vector<long long int>&memo){
    if(memo[n] == -1){
        long long int res;
        if(n==1 || n==0){
            res = n;
        }
        else{
            res = fib(n-1, memo) + fib(n-2, memo);
        }
        memo[n] = res;
    }
    return memo[n];
}


int main(){

    int n;
    cout << "Enter the number: ";
    cin >> n;
    vector<long long int>memo(n+1, -1);
    cout << fib(n, memo) <<'\n';

    return 0;
}