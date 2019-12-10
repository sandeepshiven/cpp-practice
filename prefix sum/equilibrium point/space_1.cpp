 
#include <bits/stdc++.h>
using namespace std;

bool find_equil(int*, int);

int main(){
    cout<<"Enter the size of the array: ";
    int size,start, end;
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<<" elements of the array\n";
    for(int i=0; i<size;i++)
       cin >> arr[i];
    if(find_equil(arr,size))
        cout << "Yes"<<'\n';
    else
        cout << "No"<<'\n';   
    
    return 0;

}

bool find_equil(int a[], int n){

    int sum =0;
    for(int i=0; i<n;i++){
        sum += a[i];
    }
    int l_sum=0;
    for(int i=0; i<n;i++){
        if(l_sum == sum - a[i])
            return true;
        l_sum += a[i];
        sum -= a[i]; 
    }
    return false;
}







