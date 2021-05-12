#include <bits/stdc++.h>
using namespace std;

int sol(vector<int>&arr, int i, int j, int sum){

    if(i+1 == j){
        return max(arr[i], arr[j]);
    }

    return max(sum - sol(arr, i+1, j, sum - arr[i]), 
                sum - sol(arr, i, j-1, sum-arr[j]));

}

int main(){

    int n;
    cout << "Enter the no. of items: ";
    cin >> n;
    cout << "Enter the items: ";
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Player 1 score: " << sol(arr, 0, n-1, accumulate(arr.begin(), arr.end(), 0));
    cout << '\n';

    return 0;
}