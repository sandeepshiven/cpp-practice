#include <bits/stdc++.h>
using namespace std;

int sum(vector<int>&arr, int i, int j){
    int res = 0;
    while(i<=j){
        res += arr[i];
        i++;
    }
    return res;
}

int minPages(vector<int>&arr, int n, int k){

    if(k==1){
        return sum(arr, 0, n-1);
    }
    if(n==1){
        return arr[0];
    }

    int res = INT_MAX;
    for(int i=1; i<n; i++){
        res = min(res, max(minPages(arr, i, k-1), sum(arr, i, n-1)));
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