 
#include <bits/stdc++.h>
using namespace std;

int maxdiff(int *,int );


int main(){
    cout<<"Enter the size of the array: ";
    int size;
    cin >>size;
    int arr[size];
    for(int i=0; i<size;i++)
       cin >> arr[i];
    cout << "The maximum difference is: "<<maxdiff(arr,size)<<'\n';
    return 0;

}

int maxdiff(int a[],int n){
    int result = a[1]-a[0];
    for(int i=0; i<n-1;i++){
        for(int j=i+1;j<n;j++){
            result = max(result,a[j]-a[i]);
        }
    }
    return result; 
}

