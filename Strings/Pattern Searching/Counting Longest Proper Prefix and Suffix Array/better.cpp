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



void fillLPS(string str, vector<int>&lps){
    int n = str.length();
    lps[0] = 0;
    int i=1, len=0;
    while(i<n){
        if(str[len] == str[i]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else{
                len = lps[len-1];
            }
        }
    }
}