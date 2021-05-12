#include <bits/stdc++.h>
using namespace std;


int minJumps(vector<int>&jumps, int n, int index){

    if(index > n){
        return INT_MAX;
    }
    if(index == n-1){
        return 0;
    }
    else{
        int res=INT_MAX;
        for(int i=1; i<=jumps[index]; i++){
            int rest_jumps = minJumps(jumps, n, index+i);
            if(rest_jumps != INT_MAX){
                res = min(res, rest_jumps+1);
            }
        }
        return res;
    }

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
    cout << "Min jumps: " << minJumps(jumps, n, 0) << '\n';

    return 0;
}