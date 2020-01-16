#include<bits/stdc++.h>

using namespace std;
int inversion(vector<int> &arr, int n);



int main(){

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    vector<int> arr(size);

    cout << "Enter the elements of array: ";

    for(auto i=arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    cout << inversion(arr, size) << '\n';


    return 0;
}


int inversion(vector<int> &arr, int n){

    int ans=0;

    for(int i=0; i<n-1; i++){
        for(int j= i+1; j<n ; j++){
            if(arr[i] > arr[j]){
                ans++;
            }
        }
    }

    return ans;

}




















