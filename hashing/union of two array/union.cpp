#include <bits/stdc++.h>
using namespace std;


int main(){
    int s,temp,count=0;
    cout << "Enter the size of the array 1: ";
    cin >> s;
    unordered_set<int> arr;
    cout << "Enter the elements of the array 1: ";
    for(auto i=0; i < s; i++){
        cin >> temp;        
        arr.insert(temp); 
    }
    cout << "Enter the size of the array 2: ";
    cin >> s;
    cout << "Enter the elements of the array 2: ";
    for(auto i=0; i < s; i++){
        cin >> temp;
        arr.insert(temp);         
    }
  
    cout << "Union has " << arr.size() <<" elements\n";
    
    return 0;
}




















