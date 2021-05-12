#include <bits/stdc++.h>
using namespace std;


int maxCut(int n, int a, int b, int c){

    if(n<0){
        return -1;
    }
    if(n == 0){
        return 0;
    }

    int res = max({maxCut(n-a, a, b, c),
                    maxCut(n-b, a, b, c),
                    maxCut(n-c, a, b, c)
                });

    if(res == -1){
        return -1;
    }
    return res+1;
}

int main(){

    int n, a, b, c;
    cout << "Enter the size of rod: ";
    cin >> n;
    cout << "Enter values of a, b and c: ";
    cin >> a >> b >> c;
    cout<< maxCut(n, a, b, c) << '\n';

    return 0;
}