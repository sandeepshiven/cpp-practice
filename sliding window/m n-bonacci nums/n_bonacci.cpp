#include <bits/stdc++.h>
using namespace std;

void nbonacci(int,int);
void print(int *,int );

int main(){

    int n,m;
    cout << "Enter the value of N: ";
    cin >>n;
    cout << "Enter the value of M: ";
    cin >>m;
    cout<<"The first "<<m<<" "<<n<<"-bonacci numbers are:\n";
    nbonacci(n,m);
    cout <<'\n';
    return 0;
}

void nbonacci(int n, int m){
    int bonacci[m];
    for(int i=0;i<n-1;i++)
        bonacci[i] = 0;
    bonacci[n-1]=1;
    int curr_sum = 1;
    for(int i=n; i<m; i++){

        bonacci[i] = curr_sum;
        curr_sum += (bonacci[i]-bonacci[i-n]);
    }
    print(bonacci,m);

}

void print(int a[], int n){
    for(int i=0; i<n; i++)
        cout << a[i]<<' ';
}







