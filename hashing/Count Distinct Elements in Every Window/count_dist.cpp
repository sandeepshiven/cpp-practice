#include<bits/stdc++.h>
using namespace std;

int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    unordered_map<int, int>hash_map;

    vector<int>arr(size);
    
    cout << "Enter the elements of the array: ";

    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    int k;
    cout << "Enter the size of the window: ";
    cin >> k;

    for(int i =0; i<k; i++){
        hash_map[arr[i]]++;
    }
    cout << hash_map.size() << "\n";

    for(int i = k; i<size; i++){
        
        hash_map[arr[i-k]]--;

        if(hash_map[arr[i-k]] == 0){
            hash_map.erase(arr[i-k]);
        }

        hash_map[arr[i]]++;

        cout << hash_map.size() << "\n";
    }

    
    return 0;
}






















