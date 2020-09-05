#include<bits/stdc++.h>

using namespace std;


bool checkEqual(vector<int>ct, vector<int>cp);


int main(){

    string txt, pat;
    cout << "Enter string: ";
    cin >> txt;
    cout << "Enter pattern: ";
    cin >> pat;
    
    vector<int>ct(256,0), cp(256, 0); 

    for(int i=0; i<pat.length(); i++){
        ct[txt[i]]++;
        cp[pat[i]]++;    
    }
    for(int i = pat.length(); i<txt.length(); i++){
        if(checkEqual(ct, cp)){
            cout << "YES" << '\n';
            return 0;
        }
        ct[txt[i]]++;
        ct[txt[i-pat.length()]]--;
    }
    cout << "NO" << '\n';
    return 0;

}

bool checkEqual(vector<int>ct, vector<int>cp){
    for(int i=0; i<256; i++){
        if(ct[i] != cp[i]){
            return false;
        }
    }
    return true;
}




























