 
#include <bits/stdc++.h>
using namespace std;

int max_app(int*, int*,int);

int main(){
    cout<<"Enter the size of the array: ";
    int size,start, end;
    cin >>size;
    int l_range[size],h_range[size];
    cout << "Enter "<<size<<" elements of lower range \n";
    for(int i=0; i<size;i++)
       cin >> l_range[i];
    cout << "Enter "<<size<<" elements of upper range \n";
    for(int i=0; i<size;i++)
       cin >> h_range[i];
    
    cout << "The maximum appearing element in the ranges is: "<< max_app(l_range,h_range,size)<<'\n';

    return 0;
}


int max_app(int *l, int *h,int n){
     
    vector<int>arr(1000,0);
    for(int i=0; i<n; i++){
        arr[l[i]]++;
        arr[h[i]+1]--;
    }
    int max_app = arr[0],result;
    for(int i=1;i<1000; i++){
        arr[i] += arr[i-1];
        if(max_app<arr[i]){
            max_app = arr[i];
            result = i;
        }
    }
    return result;

}


