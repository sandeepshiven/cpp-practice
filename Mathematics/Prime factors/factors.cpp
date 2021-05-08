#include <bits/stdc++.h>
using namespace std;

void printFactors(int n){

    if(n==1){
        cout << 1 << '\n';
        return;
    }
    while(n%2 == 0){
        cout << 2 << " ";
        n /=2;
    }
    while(n%3 == 0){
        cout << 3 << " ";
        n /=3;
    }
    for(int i=5; i*i <= n; i += 6){
        while (n%i == 0){
            cout << i << " ";
            n /= i;
        }
        while (n%(i+2) == 0){
            cout << i+2 << " ";
            n /= (i+2);
        }
    }
    if(n>3){
        cout << n;
    }
    cout << '\n';
}

int main(){

    int n;
    cout << "Enter the number: ";
    cin >> n;
    printFactors(n);

    return 0;
}