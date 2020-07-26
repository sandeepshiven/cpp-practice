#include <bits/stdc++.h>
using namespace std;
int longest_sub(vector<int> &prefix, int n);

int main(){
    int s,temp,sum;
    cout << "Enter the size of the array : ";
    cin >> s;
    vector<int>arr1(s), arr2(s);
    cout << "Enter the elements of the array 1: ";
    
    for(auto i=0; i < s; i++){
        cin >> arr1[i]; 
    }
    cout << "Enter the elements of the array 2: ";
    for(auto i=0; i < s; i++){
        cin >> temp;
        arr2[i] = arr1[i]-temp; 
    }
    for(auto i=1; i < s; i++){
        arr2[i] = arr2[i] + arr2[i-1];
    }
    
    
    cout << longest_sub(arr2, s) << "\n";
   
    return 0;
}

int longest_sub(vector<int> &prefix, int n){

    unordered_map<int, int> m;
    int res=0;
    for(auto i=0; i<n; i++){
        if(prefix[i] == 0){
            res = i+1;
        }
        if(m.find(prefix[i]) == m.end()){
            m[prefix[i]] = i;
        }
        if(m.find(prefix[i]) != m.end()){
            res = max(res, i-m[prefix[i]]);
        }

    }
    return res;
    
}


















