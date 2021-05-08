#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the number: ";
    cin >> n;
    int temp = n, res = 0;

    while(temp){
        res = (res*10) + (temp%10);
        temp /= 10;
    }
    if(res == n){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }




    return 0;
}