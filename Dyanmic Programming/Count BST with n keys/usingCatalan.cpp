#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    
    if(a==0){
        return b;
    }
    return gcd(b%a, a);
}

int nCr(int n, int r){

    int p=1, k=1;

    if(n-r < r){
        r = n-r;
    }

    if(r != 0){

        while(r){
            
            p *= n;
            k *= r;

            int m = gcd(p, k);

            p /= m;
            k /= m;
            n--;
            r--;

        }

    }
    else{
        p=1;
    }
    return p;

}


int countBST(int n){

    return ((long double)1/(n+1)) * nCr(2*n, n);
}


int main(){
    
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;
    cout << "No. of BST: " << countBST(n);
    cout << '\n';

    return 0;
}