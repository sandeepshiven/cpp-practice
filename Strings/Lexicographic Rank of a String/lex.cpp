#include<bits/stdc++.h>

using namespace std;


long long int factorial(int n);


int main(){

    string txt;
    cout << "Enter string: ";
    cin >> txt;
    int n = txt.length();

    long long int mul = factorial(n),res = 1;
    
    vector<int>count(256,0); 

    for(int i=0; i<n; i++){
        count[txt[i]]++;
            
    }
    for(int i = 1; i<256; i++){
        count[i] += count[i-1];
    }
    for(int i =0; i<n-1; i++){
        mul = mul/(n-i);
        res += count[txt[i]-1]*mul;
        for(int j=txt[i]; j<256; j++){
            count[j]--;
        }

    }
    cout << res << '\n';
    


    return 0;

}


long long int factorial(int n){
    long long int res = 1;
    while(n){
        res *= n;
        n--;
    }
    return res;
}


























