#include<bits/stdc++.h>

using namespace std;

void cycle_sort(vector<int> &arr, int n);


int main(){

    cout << "Enter the size of the array: ";
    int s;
    cin >> s;
    vector<int> arr(s);
    cout<< "Enter the elements of the array: ";
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    cycle_sort(arr,  s);

    for(auto i: arr){
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}


void cycle_sort(vector<int> &arr, int n){
    
    
    for(int cs =0 ; cs < n-1; cs++){

        int item = arr[cs];
        int pos = cs;

        for(int i= cs+1; i<n; i++){
            if(arr[i]<item){
                pos++;
            }
        }
        swap(item, arr[pos]);

        while(pos != cs){
            pos = cs;
            for(int i= cs+1; i<n; i++){
                if(arr[i]<item){
                    pos++;
                }
            }
            swap(item, arr[pos]);
        }

    }
}
































