#include<bits/stdc++.h>

using namespace std;

void l_partion(vector<int> &arr, int l, int h, int p);



int main(){
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    cout << "Enter the elements of the array: ";
    vector<int> arr(size);
    for(auto i=arr.begin(); i!= arr.end(); i++){
        cin >> *i;
    }

    cout << "Enter the index of the element for partion: ";
    int point;
    cin >> point;

    l_partion(arr, 0, size-1, point); 

    for(auto i: arr)
        cout << i << " ";

    cout << '\n';


    return 0;
}



void l_partion(vector<int> &arr, int l, int h, int p){
    
    int pivot = arr[p];
    int win = l-1;
    swap(arr[p], arr[h]);
    for(int i=l; i<=h; i++){
        if(arr[i] <= pivot){
            win++;
            swap(arr[win], arr[i]);
        }
    }
    swap(arr[win+1], arr[h]);




}















