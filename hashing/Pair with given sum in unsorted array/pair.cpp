#include <bits/stdc++.h>
using namespace std;


int main(){
    int s,temp,sum;
    cout << "Enter the size of the array : ";
    cin >> s;
    cout << "Enter the sum you want to find: ";
    cin >> sum;
    unordered_set<int> arr;
    cout << "Enter the elements of the array : ";
    for(auto i=0; i < s; i++){
        cin >> temp;        
        if(arr.find(sum-temp) != arr.end()){
            cout << "YES\n";
            return 0;
        }
        arr.insert(temp); 
    }
    cout << "NO\n";
    
    return 0;
}




















