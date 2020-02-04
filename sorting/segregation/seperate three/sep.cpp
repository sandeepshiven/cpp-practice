















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

    int l = -1, r=n;
    while(true){
        
        do{
            l++;
        }while(arr[l] == 0);

        do{
            r--;
        }while(arr[r] >= 1);
        
        if(l >= r)
            break;
        swap(arr[l], arr[r]);

    }

    l--;
    r=n;
    while(true){
        
        do{
            l++;
        }while(arr[l] == 1);

        do{
            r--;
        }while(arr[r] == 2);
        
        if(l >= r)
            break;
        swap(arr[l], arr[r]);

    }

}









































