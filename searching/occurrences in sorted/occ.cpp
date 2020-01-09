#include<bits/stdc++.h>

using namespace std;
int bin_search_left(vector<int> &vec, int low, int high, int ele);
int bin_search_right(vector<int> &vec, int low, int high, int ele, int n);


int main(){

    int s;
    cout << "Enter the size of the array: ";
    cin >> s;
    vector<int> arr(s);
    cout << "Enter the elements: ";
    for(auto i=arr.begin(); i !=arr.end(); i++){
        cin >> *i;
    }
    sort(arr.begin(), arr.end());
    cout << "Sorted array is: ";
    for(auto i: arr){
        cout << i <<" ";
    }
    int x;
    cout << "\nEnter the element you want to search: ";
    cin >> x;
    cout << "The no. of occurrences is: "<< (bin_search_right(arr,0,s-1,x,s)-bin_search_left(arr,0,s-1,x)) + 1<< '\n';

    return 0;

}

int bin_search_left(vector<int> &vec, int low, int high, int ele){

    if(low > high){
        return 0;
    }

    

    int mid = (low+high)/2;
    if((vec[mid]==ele) && (mid == 0 || vec[mid-1] != ele)){
        return mid;        
    }

    else if (vec[mid] >= ele){
        return bin_search_left(vec, low, mid-1, ele);
    }
    else{
        return bin_search_left(vec, mid+1, high, ele);
    }

  

}

int bin_search_right(vector<int> &vec, int low, int high, int ele, int n){

    if(low > high){
        return -1;
    }

    

    int mid = (low+high)/2;
    if((vec[mid]==ele) && (mid == (n-1) || vec[mid+1] != ele)){
        return mid;        
    }

    else if (vec[mid] > ele){
        return bin_search_right(vec, low, mid-1, ele, n);
    }
    else{
        return bin_search_right(vec, mid+1, high, ele, n);
    }

  

}












