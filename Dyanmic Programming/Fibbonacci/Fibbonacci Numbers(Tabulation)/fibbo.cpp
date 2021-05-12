#include <bits/stdc++.h>
using namespace std;

long long int fib(int n){

    vector<long long int>f(n+1);
    f[0]=0, f[1]=1;
    for(int i=2; i<=n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}


int main(){

    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    cout << fib(n) <<'\n';

    return 0;
}