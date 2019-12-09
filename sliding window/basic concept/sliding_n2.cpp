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

    int result = INT_MIN,sum = 0;

    for(int i=0; i<n-k+1; i++){
        sum = 0;
        for(int j=i;j<k+i;j++){
            sum += a[j];
        }
        result = max(result, sum);
    }

    return result;
}







