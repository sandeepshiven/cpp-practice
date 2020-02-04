#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &vec, int n, int exp);
void radix_sort(vector<int> &arr, int n);


int main() {

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    cout << "Enter the elements of the array: ";

    vector<int> arr(size);
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    radix_sort(arr, size);

    for(auto i: arr)
        cout << i << " ";
    
    cout << '\n';


	return 0;
}


void radix_sort(vector<int> &arr, int n){
    int max = *(max_element(arr.begin(), arr.end()));
    for(int i = 1; max/i >0; i *= 10){
        counting_sort(arr, n, i);
    }
}



void counting_sort(vector<int> &arr, int n, int exp){
    
    
    vector<int>count(10);
    vector<int>temp(n);
    for(auto i: arr){
        count[(i/exp)%10]++;
    }
    for(int i=1; i<=9; i++){
        count[i] += count[i-1];
    }
    
    for(int i=n-1; i>=0; i--){
        temp[count[(arr[i]/exp)%10]-1] = arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
}





































