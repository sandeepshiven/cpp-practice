#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &vec, int n);


int main() {

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    cout << "Enter the elements of the array: ";

    vector<int> arr(size);
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    insertion_sort(arr, size);

    for(auto i: arr)
        cout << i << " ";
    
    cout << '\n';


	return 0;
}


void insertion_sort(vector<int> &vec, int n){

    for(int i=1; i<n; i++){
        int key = vec[i];
        int j = i-1;
        /// insertion if the current is less the previous

        while(j>=0 && vec[j]> key){
            vec[j+1] = vec[j];
            j--;
        }

        vec[j+1] = key;

    }

}










