#include <bits/stdc++.h>
using namespace std;
int longest_sum(vector<int> &prefix, int n, int sum);

int main(){
    int s,temp,sum;
    cout << "Enter the size of the array : ";
    cin >> s;
    vector<int>prefix(s);
    cout << "Enter the elements of the array : ";
    cin >> prefix[0];
    for(auto i=1; i < s; i++){
        cin >> temp;        
        prefix[i] = temp + prefix[i-1]; 
    }
    cout << "Enter the sum you want to find: ";
    cin >> sum;
    cout << longest_sum(prefix, s, sum) << "\n";
   
    return 0;
}

int longest_sum(vector<int> &prefix, int n, int sum){

    unordered_map<int, int> m;
    int res=0;
    for(auto i=0; i<n; i++){
        if(prefix[i] == sum){
            res = i+1;
        }
        if(m.find(prefix[i]-sum) == m.end()){
            m[prefix[i]] = i;
        }
        if(m.find(prefix[i]-sum) != m.end()){
            res = max(res, i-m[prefix[i]-sum]);
        }

    }
    return res;
    
}


















