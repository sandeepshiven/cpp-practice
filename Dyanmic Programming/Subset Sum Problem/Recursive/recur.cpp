#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>&arr, int n, int sum){

    if(n==0){
        return sum==0 ? 1:0;
    }

    return countSubsets(arr, n-1, sum) + countSubsets(arr, n-1, sum - arr[n-1]);

}

int main(){

    int n;
    cout << "Enter the size of array: ";
    cin >> n; 
    cout << "Enter the elements of array: ";
    vector<int>arr(n);

    for(int i=0; i< n; i++){
        cin >> arr[i];
    }
    cout << "Enter the sum: ";
    int sum;
    cin >> sum;
    cout << "Total subsets are: " << countSubsets(arr, n, sum)<< '\n';


    return 0;
}