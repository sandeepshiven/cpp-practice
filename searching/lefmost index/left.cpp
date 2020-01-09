#include<bits/stdc++.h>

using namespace std;
int bin_search(vector<int> &vec, int low, int high, int ele);


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
    cout << "The left most index is: "<< bin_search(arr,0,s-1,x) << '\n';

    return 0;

}

int bin_search(vector<int> &vec, int low, int high, int ele){

    if(low > high){
        return -1;
    }

    static int index = -1;

    int mid = (low+high)/2;
    if(vec[mid]==ele){
        index = mid ;
        bin_search(vec, low, mid-1, ele);
        return index;        
    }

    else if (vec[mid] > ele){
        return bin_search(vec, low, mid-1, ele);
    }
    else{
        return bin_search(vec, mid+1, high, ele);
    }

  

}












