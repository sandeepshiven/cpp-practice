#include <bits/stdc++.h>
using namespace std;
int longest_sub(vector<int> &prefix, int n);

int main(){
    int s,temp,sum;
    cout << "Enter the size of the array : ";
    cin >> s;
    vector<int>prefix(s);
    cout << "Enter the elements of the array : ";
    cin >> temp;
    if(temp == 0){
        temp = -1;
    }
    prefix[0] = temp;
    for(auto i=1; i < s; i++){
        cin >> temp;
        if(temp == 0){
            temp = -1;
        }
        prefix[i] = temp + prefix[i-1]; 
    }
    
    cout << longest_sub(prefix, s) << "\n";
   
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


















