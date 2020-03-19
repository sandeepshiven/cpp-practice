#include <bits/stdc++.h>
using namespace std;


int main(){
    int s,temp;
    cout << "Enter the size of the array: ";
    cin >> s;
    
    unordered_map<int, int> arr;
    cout << "Enter the elements of the array: ";
    for(auto i=0; i < s; i++){
        cin >> temp;
        arr[temp]++; 
    }
    s=0;
    for(auto i=arr.begin(); i != arr.end(); i++){
        
        cout << i->first << " - " << i->second << "\n";
    }
    cout << "\n";
    
    return 0;
}




















