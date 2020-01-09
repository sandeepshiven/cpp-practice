#include<bits/stdc++.h>

using namespace std;
 int bin_search(vector<int> &vec,  int low, int high, int ele);
 int find_ele(vector<int> &vec, int x);

int main(){

    int s ;
    // cout << "Enter the size of the array: ";
    // cin >> s;
    vector<int> arr(100000);
    //cout << "Enter the elements: ";
    for(auto i=arr.begin(); i !=arr.end(); i++){
        cin >> *i;
    }
    sort(arr.begin(), arr.end());
    // cout << "Sorted array is: ";
    //  for(auto i: arr){
    //      cout << i <<" ";
    //  }
    int x;
    //cout << "\nEnter the element you want to search: ";
    cin >> x;
    cout << "The element is at index: "<< find_ele(arr,x) << '\n';

    return 0;

}

int find_ele(vector<int> &vec, int x){

    if(vec[0]==x){
        return 0;
    }

    int i=1;
    while(vec[i] < x){
        i *= 2;
    }
    if(vec[i]==x){
        return i;
    }
    else{

    return bin_search(vec, i/2, i, x);
    }

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












