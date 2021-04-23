#include <bits/stdc++.h>
using namespace std;

void permute(string s, int l, int r){

    if(l == r){
        if(s.find("ab") == string::npos){

            cout << s;
            cout << '\n';
        }
        return;
    }
    else{
        for(int i=l; i<r; i++){
            swap(s[i], s[l]);
            permute(s, l+1, r);
            swap(s[i], s[l]);
        }
    }
}

int main(){
    
    string s;
    cout << "Enter the string: ";
    cin >>s;
    permute(s, 0, s.size());



    return 0;
}