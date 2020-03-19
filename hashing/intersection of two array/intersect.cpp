#include <bits/stdc++.h>
using namespace std;


int main(){
    int s,temp;
    cout << "Enter the size of the array 1: ";
    cin >> s;
    unordered_set<int> arr1, arr2;
    cout << "Enter the elements of the array 1: ";
    for(auto i=0; i < s; i++){
        cin >> temp;
        
        arr1.insert(temp); 
    }
    cout << "Enter the size of the array 2: ";
    cin >> s;
    cout << "Enter the elements of the array 2: ";
    for(auto i=0; i < s; i++){
        cin >> temp;
        
        arr2.insert(temp); 
    }
    unordered_map<int, int> arr;
    for(auto i=arr1.begin(); i != arr1.end(); i++){
        
       arr[*i]++;
    }
    for(auto i=arr2.begin(); i != arr2.end(); i++){
        
       arr[*i]++;
    }
    s=0;
    for(auto i=arr.begin(); i != arr.end(); i++){
        
        if(i->second > 1)
            s++;
    }
    cout << s <<"\n";
    
    return 0;
}




















