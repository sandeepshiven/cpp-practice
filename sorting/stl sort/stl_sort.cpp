#include<bits/stdc++.h>

using namespace std;

int main(){

    int arr[] = {6,8,9,3,4,3,1};

    sort(arr, arr+7);
    for(int i: arr){
        cout << i << " ";
    }
    cout << "\n";
    sort(arr, arr+7, greater<int>());
    for(int i: arr){
        cout << i << " ";
    }
    cout << "\n";


    return 0;
}











