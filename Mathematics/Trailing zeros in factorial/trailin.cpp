#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cout << "Enter the number: ";
    cin >> n;
    int res = 0;
    // for(int i=1; i<=n; i++){
    //     int temp = i;
    //     while(temp%5 == 0){
    //         res++;
    //         temp /= 5;
    //     }
    // }

    for(int i=5; i<=n; i *= 5){
        res = res + n/i;
    }

    cout << res << '\n';

    return 0;
}