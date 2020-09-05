#include<bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter the string: ";
    string str;
    getline(cin, str);
    
    int start=0;

    for(int end=0; end<str.length(); end++){
        if(str[end] == ' '){
            reverse(&str[0]+start, &str[0]+end);
            
            start = end+1;
        }
    }
    reverse(&str[0]+start, &str[0]+str.length());
    reverse(str.begin(), str.end());

    cout << str << "\n";
    return 0;
}