#include <bits/stdc++.h>
using namespace std;

int max_sub_sum(int *,int, int);


int main(){
    cout<<"Enter the size of the array: ";
    int size,k;
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<<" elements of the array\n";
    for(int i=0; i<size;i++)
       cin >> arr[i];
    cout <<"Enter the value of k: ";
    cin >> k;
    cout << "The max sum of subarray with size "<<k<<" is: "<<max_sub_sum(arr,size,k)<<'\n';
    return 0;

}


int max_sub_sum(int *a,int n, int k){

    int curr_sum = 0,result = INT_MIN;

    for(int i=0;i<k;i++){
        curr_sum += a[i]; 
    }

    for(int i=k; i<n; i++){
        curr_sum += (a[i]-a[i-k]);
        result = max(result, curr_sum);
    }

    return result;

}







