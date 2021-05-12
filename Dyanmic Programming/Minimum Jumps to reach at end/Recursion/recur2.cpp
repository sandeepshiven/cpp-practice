#include <bits/stdc++.h>
using namespace std;


int minJumps(vector<int>&jumps, int n){

    
    if(n == 1){
        return 0;
    }
    int res=INT_MAX;
    for(int i=0; i<=n-2; i++){

        if(i + jumps[i] >= n-1){

            int rest_jumps = minJumps(jumps, i+1);
            if(rest_jumps != INT_MAX){
                res = min(res, rest_jumps+1);
            }
        }
    }
    return res;


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