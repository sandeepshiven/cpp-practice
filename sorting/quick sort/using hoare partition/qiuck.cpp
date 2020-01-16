#include<bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int l, int h);
void quick_sort(vector<int> &arr, int l, int h);



int main(){

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    vector<int> arr(size);

    cout << "Enter the elements of array: ";
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    quick_sort(arr, 0, size-1);

    for(auto i: arr)
        cout << i << " ";


    cout << '\n';   

    return 0;
}


void quick_sort(vector<int> &arr, int l, int h){

    if(l<h){
        int p = partition(arr, l, h);

        quick_sort(arr, l, p);
        quick_sort(arr, p+1, h);
    }
}

int partition(vector<int> &arr, int l, int h){
    int pivot= arr[l];
    int left = l-1, right = h+1;

    while(true){

        do{
            left++;
        }while(arr[left] < pivot);

        do{
            right--;
        }while(arr[right] > pivot);

        if(left >= right)
            break;

        swap(arr[left], arr[right]);
    }
    return right;

}








