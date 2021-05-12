#include <bits/stdc++.h>
using namespace std;

int isfeasible(vector<int>&arr, int n, int k, int ans){
    
    int req = 1, sum=0;

    for(int i=0; i<n; i++){
        if(sum + arr[i] > ans){
            req++;
            sum = arr[i];
        }
        else{
            sum += arr[i];
        }
    }
    return req <= k;
}

int minPages(vector<int>&arr, int n, int k){

    int sum =0, mx=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        mx = max(mx, arr[i]);
    }

    int low = mx, high = sum, mid, res=0;
    while(low<=high){
        mid = (low+high)/2;
        if(isfeasible(arr, n, k, mid)){
            res = mid;
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }
    return res;
}

int main(){

    int n;
    cout << "Enter the number of books: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the pages in book: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Enter the number of students: ";
    int k;
    cin >> k;
    cout << "Min no. of pages read by a student is: " << minPages(arr, n, k)<<'\n';

    return 0;
}