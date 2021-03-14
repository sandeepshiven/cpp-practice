#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,temp, s=0;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<double>arr(n);
    cout << "Enter the elements of array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
        s++;
        int j = i;
        while(j>0 && arr[j] < arr[j-1]){
            swap(arr[j], arr[j-1]);
            j--;
        }
        if(s%2){
            cout << arr[s/2]<<" ";
        }
        else{
            cout << (arr[s/2]+arr[(s-1)/2])/2 << " ";
        }
    }
    cout << "\n";


    return 0;
}