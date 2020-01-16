#include<bits/stdc++.h>


using namespace std;
void h_partition(vector<int> &arr, int l, int h);


int main(){

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    cout << "Enter the elements of the array: ";
    vector<int> arr(size);
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }
    h_partition(arr,0, size-1);

    for(auto i: arr)
        cout << i << " ";

    cout << '\n';
    return 0;
}



void h_partition(vector<int> &arr, int l, int h){
    
    int pivot = arr[l];
    int left = l-1, right = h+1;

    while(true){

        do{
            left++;
        }while(arr[left] < pivot);

        do{
            right--;
        }while(arr[right] > pivot);

        if(left>=right)
            break;
        swap(arr[left], arr[right]);


    }


}




























