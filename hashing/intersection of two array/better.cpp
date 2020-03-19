#include <bits/stdc++.h>
using namespace std;


int main(){
    int s,temp,count=0;
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
        if(arr1.find(temp) != arr1.end()){
            count++;
            arr1.erase(temp);
        }            
    }
  
    cout << count <<"\n";
    
    return 0;
}




















