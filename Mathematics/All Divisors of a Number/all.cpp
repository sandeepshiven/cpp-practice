#include <bits/stdc++.h>
using namespace std;

void printDivisors(int n){

    for(int i=1; i*i <= n; i++){
        if(n%i == 0){
            cout << i << " ";
            if(i != n/i){
                cout << n/i << " ";
            }
        }
    }
    cout << '\n';
}

int main(){

    int n;
    cout << "Enter the number: ";
    cin >> n;
    printDivisors(n);

    return 0;
}