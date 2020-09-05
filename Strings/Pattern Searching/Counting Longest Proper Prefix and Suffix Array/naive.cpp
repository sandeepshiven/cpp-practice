#include<bits/stdc++.h>

using namespace std;

void fillLPS(string str, vector<int>&vec);
int longProPreSuff(string str, int n);


int main(){

    cout << "Enter String: ";
    string str;
    getline(cin, str);

    vector<int>vec(str.length());

    fillLPS(str, vec);

    for(auto i: vec){
        cout << i << " " << '\n';
    }

    return 0;
}


int longProPreSuff(string str, int n){
    for(int len = n-1; len>0; len--){
        bool flag = true;
        for(int i =0; i<len; i++){
            if(str[i] != str[n-len+i]){
                flag = false;
            }
        }
        if(flag){
            return len;
        }
    }
    return 0;
}


void fillLPS(string str, vector<int>&vec){
    for(int i=0; i<str.length(); i++){
        vec[i] = longProPreSuff(str, i+1);
    }
}