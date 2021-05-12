#include <bits/stdc++.h>
using namespace std;

int minMul(vector<int>&arr, int i, int j){

    if(i+1 == j){
        return 0;
    }

    int res = INT_MAX;
    for(int k=i+1; k<j; k++){
        res = min(res, minMul(arr, i, k)+
                        minMul(arr, k, j)+
                        (arr[i]*arr[k]*arr[j]));
    }
    return res;

}

int main(){

    int n;
    cout << "Enter the size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Min multiplications are: " << minMul(arr, 0, n-1) << "\n";
    

    return 0;
}