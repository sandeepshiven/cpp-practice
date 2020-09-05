#include<bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter the string: ";
    string text, pat;
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pat);

    int n = text.length();
    int m = pat.length();

    for(int i=0; i<= n-m; ){
        int j;
        for(j=0; j<m; j++){
            if(pat[j] != text[i+j]){
                break;
            }
        }

        if(j==m){
            cout << i << "\n";
        }
        if(j==0){
            i++;
        }
        else{
            i = i+j;
        }

    }

    return 0;
}