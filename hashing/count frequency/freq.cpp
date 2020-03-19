#include <bits/stdc++.h>
using namespace std;


int main(){
    int s,temp;
    cout << "Enter the size of the array: ";
    cin >> s;
    vector<int>  table(10000000);
    unordered_set<int> arr;
    cout << "Enter the elements of the array: ";
    for(auto i=0; i < s; i++){
        cin >> temp;
        table[temp]++;
        arr.insert(temp); 
    }
    s=0;
    for(auto i=arr.begin(); i != arr.end(); i++){
        
        cout << *i << " - " << table[*i] << "\n";
    }
    cout << "\n";
    
    return 0;
}




















