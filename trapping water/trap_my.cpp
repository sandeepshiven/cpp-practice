#include <bits/stdc++.h>
using namespace std;

int trap(int *,int);


int main(){
    cout<<"Enter the size of the array: ";
    int size;
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<<" elements of the array\n";
    for(int i=0; i<size;i++)
       cin >> arr[i];
    cout << "The volume of water trapped is: "<<trap(arr,size)<<'\n';
    return 0;

}

int trap(int a[], int n){

    int vol=0;
    int curr=0;
    int low = a[0];
    for(int i=1;i<n;i++){
        if(low>a[i]){
            curr += low - a[i];
        }
        else{
            low = a[i];
            vol += curr;
            curr = 0;
        }
    }
    curr=0;
    low = a[n-1];
    for(int i=n-2;i>=0;i--){
        if(low>a[i]){
            curr += low - a[i];
        }
        else{
            low = a[i];
            vol += curr;
            curr = 0;
        }
    }
    return vol;

}