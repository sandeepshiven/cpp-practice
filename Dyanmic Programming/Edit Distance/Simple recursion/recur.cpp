#include <bits/stdc++.h>
using namespace std;

int editDist(string s1, string s2, int m, int n){

    if(m==0){
        return n;
    }
    if(n == 0){
        return m;
    }
    
    if(s1[m-1] == s2[n-1]){
        return editDist(s1, s2, m-1, n-1);
    }
    else{
        return (1 + min({editDist(s1, s2, m, n-1), 
                        editDist(s1, s2, m-1, n),
                        editDist(s1, s2, m-1, n-1)}));
    }

}

int main(){

    string s1, s2;
    cout << "Enter string 1: ";
    cin >> s1;
    cout << "Enter string 2: ";
    cin >> s2;
    cout << "Min of replace, insert and delete: " << editDist(s1, s2, s1.size(), s2.size());
    cout << '\n';

    return 0;
}