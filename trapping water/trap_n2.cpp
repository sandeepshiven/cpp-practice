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

    int lmax,rmax,result = 0;
    for(int i=1;i<n-1;i++){

        lmax = a[i];
        for(int j=0; j<i; j++){
            lmax = max(lmax,a[j]);
        }

        rmax = a[i];
        for(int j=i+1; j<n; j++){
            rmax = max(rmax,a[j]);
        }

        result +=  (min(lmax, rmax)-a[i]);

    }

    return result;    
}