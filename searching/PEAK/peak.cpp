#include<bits/stdc++.h>

using namespace std;
int find_peak(vector<int> &vec, int low, int high, int n);




int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter the elements of the array: ";
    for(auto i = arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    cout << "The peak element is: "<< find_peak(arr, 0, size-1, size) << '\n';

    return 0;

}

int find_peak(vector<int> &vec, int low, int high, int n){

    int mid = (low+high)/2;

    if((mid==0 || vec[mid-1] < vec[mid]) && (mid==n-1 || vec[mid+1] < vec[mid])){
        return vec[mid];
    }

    else if(mid > 0 && vec[mid-1] > vec[mid] ){
        return find_peak(vec, 0, mid-1, n);
    }
    else return find_peak(vec, mid+1, high, n);



}











