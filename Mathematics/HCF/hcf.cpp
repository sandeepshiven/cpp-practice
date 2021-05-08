#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){

    if(a == 0){
        return b;
    }
    return gcd(b%a, a);
}

int main(){

    int a, b, res;
    cout << "Enter the two numbers: ";
    cin >> a >> b; 
    for(int i=min(a, b); i>=1; i--){
        if(a%i == 0 && b%i==0){
            res = i;
            break;
        }
    }

    cout << res << '\n';
    return 0;
}