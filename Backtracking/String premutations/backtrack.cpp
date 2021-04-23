#include <bits/stdc++.h>
using namespace std;

bool isSafe(string s, int l, int i, int r){
    if(l != 0 && s[l-1] == 'a' && s[i] == 'b'){
        return false;
    }
    if(r == l+1 && s[i] == 'a' && s[l]=='b'){
        return false;
    }
    return true;
}

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
            if(isSafe(s, l, i, r)){

                swap(s[i], s[l]);
                permute(s, l+1, r);
                swap(s[i], s[l]);
            }
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