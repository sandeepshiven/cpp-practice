#include <bits/stdc++.h>
using namespace std;

int ceilIndex(vector<int>&tail, int l, int r, int x){

    int mid;
    while(l<r){
        mid = (l+r)/2;
        if(tail[mid] >= x){
            r = mid;
        }
        else{
            l = mid+1;
        }

    }
    return r;

}

int lis(vector<int>&arr, int n){

    vector<int>tail;
    tail.push_back(arr[0]);

    
    for(int i=1; i<n; i++){
        if(arr[i] > tail.back()){
            tail.push_back(arr[i]);
        }
        else{
            int c = ceilIndex(tail, 0, tail.size()-1, arr[i]);
            tail[c] = arr[i];
        }
    }
    return tail.size();
}


int main(){


    int n; 
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "LIS length: "<< lis(arr, n)<< '\n';

    return 0;
}