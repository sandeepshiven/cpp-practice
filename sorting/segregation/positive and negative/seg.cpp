#include <bits/stdc++.h>
using namespace std;

void seperate(vector<int> &vec, int n);


int main() {

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    cout << "Enter the elements of the array: ";

    vector<int> arr(size);
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    seperate(arr, size);

    for(auto i: arr)
        cout << i << " ";
    
    cout << '\n';


	return 0;
}



void seperate(vector<int> &arr, int n){

    int l = 0, r=n-1;
    while(l<r){
        if(arr[r]>0 && arr[l] >0){
            r--;
        }
        else if(arr[r]<0 && arr[l]<0){
            l++;
        }
        else if(arr[l]<0 && arr[r]>0){
            l++;
        }
        else{
            swap(arr[r], arr[l]);
            l++;
            r--;
        }
    }

}

























