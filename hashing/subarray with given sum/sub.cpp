#include <bits/stdc++.h>
using namespace std;


int main(){
    int s,temp,sum;
    cout << "Enter the size of the array : ";
    cin >> s;
    vector<int>prefix(s);
    unordered_set<int> arr;
    cout << "Enter the elements of the array : ";
    cin >> prefix[0];
    for(auto i=1; i < s; i++){
        cin >> temp;        
        prefix[i] = temp + prefix[i-1]; 
    }
    cout << "Enter the sum you want to find: ";
    cin >> sum;
    for(auto i=0; i < s; i++){
        if(arr.find(prefix[i]-sum) != arr.end() || prefix[i]==sum){
            cout << "YES\n";
            return 0;
        }
        arr.insert(prefix[i]);
    }
    cout << "NO\n";
    
    return 0;
}




















