#include <bits/stdc++.h>
using namespace std;

int maxprofit(int *,int);


int main(){
    cout<<"Enter the size of the array: ";
    int size;
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<<" elements of the array\n";
    for(int i=0; i<size;i++)
       cin >> arr[i];
    cout << "The maximum profit is: "<<maxprofit(arr,size)<<'\n';
    return 0;

}

int maxprofit(int a[],int n){

    int profit=0;
    for(int i=1;i<n;i++){
        if(a[i] > a[i-1]) // we will buy stocks when its price is at lowest and sell at highest price
            profit += a[i]-a[i-1]; // using cumulative approach (8-3=5)+(12-8=4) == (12-3=9)
    }
    return profit;
}