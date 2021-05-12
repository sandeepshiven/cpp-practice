#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){

   
    if(i == j){
        return true;
    }
    
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int palParts(string s, int i, int j){

    if(isPalindrome(s, i, j)){
        return 0;
    }
    int res = INT_MAX;
    for(int k=i; k<j; k++){
        res = min(res, 1+palParts(s, i, k)+palParts(s, k+1, j));
    }
    return res;
}

int main(){

    int n; 
    string s; 
    cout << "Enter the string: ";   
    cin >> s;
    n = s.length();
    cout << "Min cuts: " << palParts(s, 0, n-1) << '\n';
   

   return 0;
}