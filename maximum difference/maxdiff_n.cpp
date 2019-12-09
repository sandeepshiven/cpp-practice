#include <bits/stdc++.h>
using namespace std;

int maxdiff(int *,int );



int main(){
    cout<<"Enter the size of the array: ";
    int size;
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<<" elements of the array\n";
    for(int i=0; i<size;i++)
       cin >> arr[i];
    cout << "The maximum difference is: "<<maxdiff(arr,size)<<'\n';
    return 0;

}

int maxdiff(int a[],int n){
    int result = a[1]-a[0];
    int minval = a[0];
    for(int i=1;i<n;i++){
        result = max(result, a[i]-minval);
        minval = min(minval, a[i]);
    }
    return result;
}








