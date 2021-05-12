#include <bits/stdc++.h>
using namespace std;

int maxSum(vector<int>&arr, int n){

    if(n==1){
        return arr[0];
    }
    else if(n==2){
        return max(arr[0], arr[1]);
    }
    else{
        return max(maxSum(arr, n-1), arr[n-1]+maxSum(arr, n-2));
    }

}

int main(){

    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Max Sum: " << maxSum(arr, n) << '\n';

    return 0;
}