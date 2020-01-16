#include<bits/stdc++.h>


using namespace std;

int partition(vector<int> &arr, int l, int r);
int random_partition(vector<int> &arr, int l, int r);
int smallest(vector<int> &arr, int l, int r, int n);




int main(){

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    cout << "Enter the elements of the array: ";
    vector<int> arr(size);
    for(auto i = arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    cout << "Enter the nth smallest element you want to find: ";
    int nth;
    cin >> nth;

    printf("The %dth smallest element is: %d\n", nth, smallest(arr, 0, size-1, nth));

    return 0;
}

int smallest(vector<int> &arr, int l, int r, int n){

    while (l<r){
        int p = random_partition(arr, l, r);

        if (p== n-1){
            return arr[p];
        }
        else if (p > n-1){
            r = p-1;
        }
        else{
            l = p+1;
        }
        
    }
    return -1;

}

int random_partition(vector<int> &arr, int l, int r){

    srand(time(NULL));
    int i = ((rand()%(r-l+1)) + l);
    swap(arr[r], arr[i]);
    return partition(arr, l, r);

}

int partition(vector<int> &arr, int l, int r){

    int pivot = arr[r];
    int window = l-1;
    for(int i=l; i<=r-1; i++){
        if(arr[i] <= pivot){
            window++;
            swap(arr[i], arr[window]);
        }
    }
    swap(arr[r], arr[window+1]);
    return window+1;
}


















