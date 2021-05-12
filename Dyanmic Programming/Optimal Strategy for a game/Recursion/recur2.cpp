#include <bits/stdc++.h>
using namespace std;

int sol(vector<int>&arr, int i, int j){

    if(i+1 == j){
        return max(arr[i], arr[j]);
    }

    return max( 
                arr[i] + min(sol(arr, i+2, j),
                              sol(arr, i+1, j-1)),

                arr[j] + min(sol(arr, i+1, j-1),
                              sol(arr, i, j-2))
               );

}

int main(){

    int n;
    cout << "Enter the no. of items: ";
    cin >> n;
    cout << "Enter the items: ";
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Player 1 score: " << sol(arr, 0, n-1);
    cout << '\n';

    return 0;
}