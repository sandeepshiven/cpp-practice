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

    int lmax[n],rmax[n],result = 0;

        lmax[0] = a[0];
        for(int j=1; j<n; j++){
            lmax[j] = max(lmax[j-1],a[j]);
        }

        rmax[n-1] = a[n-1];
        for(int j=n-2; j>=0; j--){
            rmax[j] = max(rmax[j+1],a[j]);
        }
    for(int i=1;i<n-1;i++){

        result +=  (min(lmax[i], rmax[i])-a[i]);

    }

    return result;    
}