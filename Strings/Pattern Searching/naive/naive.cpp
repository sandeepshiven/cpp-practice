#include<bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter the string: ";
    string str, patt;
    getline(cin, str);
    cout << "Enter the pattern: ";
    getline(cin, patt);

    for(int i=0; i < str.length()-patt.length()+1; i++){
        if(str[i] == patt[0]){
            int j=i, k=0;
            while(str[j] == patt[k] && k < patt.length() && j < str.length()){
                j++;
                k++;
            }
            if(k==patt.length()){
                cout << i << '\n';
            }
        }
    }

    return 0;
}