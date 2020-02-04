#include <bits/stdc++.h>
using namespace std;

void seperate(vector<int> &vec, int n);


int main() {

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    cout << "Enter the elements of the array: ";

    vector<int> arr(size);
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    seperate(arr, size);

    for(auto i: arr)
        cout << i << " ";
    
    cout << '\n';


	return 0;
}



void seperate(vector<int> &arr, int n){

    int l = 0, r=n-1, mid = 0;
    while(mid<=r){

        switch(arr[mid])
        {
            case 0:
                swap(arr[mid], arr[l]);
                l++;
                mid++;
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(arr[mid], arr[r]);
                r--;
                break;
        
        default:
            break;
        }

        
    }

   

}









































