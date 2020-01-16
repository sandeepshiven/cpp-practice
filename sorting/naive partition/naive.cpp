#include<bits/stdc++.h>

using namespace std;

void naive_partion(vector<int> &arr, int l, int h, int p);



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

    naive_partion(arr, 0, size-1, point); 

    for(auto i: arr)
        cout << i << " ";

    cout << '\n';


    return 0;
}



void naive_partion(vector<int> &arr, int l, int h, int p){
    
    vector<int>temp(h-l+1); 
    int index=0;

    for(int i=l; i<= h; i++){
        if(arr[i] <= arr[p]){
            temp[index++] = arr[i];
        }
    }
    for(int i=l; i<= h; i++){
        if(arr[i] > arr[p]){
            temp[index++] = arr[i];
        }
    }

    for(int i=l; i<= h; i++){
        arr[i] = temp[i-l];
        }
    




}















