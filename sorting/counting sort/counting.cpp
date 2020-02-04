


#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int> &vec, int n);


int main() {

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    cout << "Enter the elements of the array: ";

    vector<int> arr(size);
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    counting_sort(arr, size);

    for(auto i: arr)
        cout << i << " ";
    
    cout << '\n';


	return 0;
}



void counting_sort(vector<int> &arr, int n){
    
    int m = *(max_element(arr.begin(), arr.end()));
    vector<int>count(m+1);
    vector<int>temp(n);
    for(auto i: arr){
        count[i]++;
    }
    for(int i=1; i<=m; i++){
        count[i] += count[i-1];
    }
    
    for(int i=n-1; i>=0; i--){
        temp[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0; i<n; i++){
        arr[i] = temp[i];
    }
}


































