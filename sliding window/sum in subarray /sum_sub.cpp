#include <bits/stdc++.h>
using namespace std;

bool find_sub_sum(int *,int, int);


int main(){
    cout<<"Enter the size of the array: ";
    int size,sum_;
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<<" elements of the array\n";
    for(int i=0; i<size;i++)
       cin >> arr[i];
    cout <<"Enter the sum you want to find: ";
    cin >> sum_;
    if(find_sub_sum(arr,size, sum_))
        cout << "The sum is in the array\n";
    else
        cout << "The sum is not in the array\n";
    
    return 0;

}

bool find_sub_sum(int a[], int n, int sum){
    
    int curr_sum = a[0],start = 0;

    for(int end=1; end < n ; end++){

        while(curr_sum>sum && start<end-1){
            curr_sum -= a[start];
            start++; 
        }

        if(curr_sum == sum)
            return true;

        if(end < n)
            curr_sum += a[end];

    }
    return false;
}











