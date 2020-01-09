#include<bits/stdc++.h>

using namespace std;
int bin_search(vector<int> &vec, int low, int high, int ele);
int find_pivot(vector<int> &vec, int low, int high);
int pivoted_bin_search(vector<int> &vec, int n, int ele);


int main(){

    int s;
    cout << "Enter the size of the array: ";
    cin >> s;
    vector<int> arr(s);
    cout << "Enter the elements: ";
    for(auto i=arr.begin(); i !=arr.end(); i++){
        cin >> *i;
    }
    // sort(arr.begin(), arr.end());
    // cout << "Sorted array is: ";
    // for(auto i: arr){
    //     cout << i <<" ";
    // }
    int x;
    cout << "\nEnter the element you want to search: ";
    cin >> x;
    int res = pivoted_bin_search(arr, s-1, x);
    cout << "The element is at index: "<< res << '\n';

    return 0;

}
int pivoted_bin_search(vector<int> &vec, int n, int ele){
    int pivot = find_pivot(vec,0,n);

    cout << "The pivot is at index: "<< pivot<<"\n";

    if(pivot == -1){
        return bin_search(vec, 0, n, ele);
    }

    if(vec[pivot] == ele){
        return pivot;
    }

    if(vec[0] <= ele){
       return bin_search(vec, 0, pivot-1, ele);
    }

    return bin_search(vec, pivot+1, n, ele);


}

int find_pivot(vector<int> &vec, int low, int high){
    if(low>high)
        return -1;

    int mid = (low + high)/2;

    if((mid < high) && (vec[mid] > vec[mid+1])){
        return mid;
    }
    if((mid > low) && (vec[mid] < vec[mid-1])){
        return mid-1;
    }
    if(vec[low] >= vec[mid]){
        return find_pivot(vec, low, mid-1);
    }
    
    return find_pivot(vec, mid+1, high);




}

int bin_search(vector<int> &vec, int low, int high, int ele){

    if(low > high){
        return -1;
    }

    
    int mid = (low+high)/2;
    if(vec[mid]==ele){
        return mid;        
    }

    else if (vec[mid] > ele){
        return bin_search(vec, low, mid-1, ele);
    }
    else{
        return bin_search(vec, mid+1, high, ele);
    }

  

}












