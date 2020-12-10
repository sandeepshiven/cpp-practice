#include<bits/stdc++.h>

using namespace std;


void generateSubset(int k,int n, vector<int>&v){
    if(k == n+1){
        for(int x: v){
            cout << x << ' ';
        }
        cout << '\n';
    }
    else{
        v.push_back(k);
        generateSubset(k+1, n, v);

        v.pop_back();
        generateSubset(k+1, n, v);
    }
}

int main(){

    cout << "Enter number of elements: ";
    int n;
    cin >>n;
    vector<int>v;
    generateSubset(1, n, v);

    return 0;
}