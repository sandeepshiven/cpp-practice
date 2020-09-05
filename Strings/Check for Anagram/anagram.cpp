#include<bits/stdc++.h>

using namespace std;

int main(){

    string str1, str2;
    cout << "Enter string 1: ";
    cin >> str1;
    cout << "Enter string 2: ";
    cin >> str2;
    
    int count[26] ={0}; 

    for(int i=0; i<str1.length(); i++){
        count[str1[i]-'a']++;
    }
    for(int i=0; i<str2.length(); i++){
        count[str2[i]-'a']--;
    }
    for(int i=0; i<26; i++){
        if(count[i] != 0){
            cout << "No" << '\n';
            return 0;
        }
    }

    cout << "Yes" << '\n';

    return 0;
}






























