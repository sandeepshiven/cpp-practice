#include<bits/stdc++.h>

using namespace std;

int main(){

    cout <<"Enter the string: ";
    string str;
    cin >> str;
    int arr[256];
    fill(arr, arr+256, -1);
    int res = INT_MAX;

    for(int i=0; i<str.length(); i++){
        int fi = arr[str[i]];
        if(fi == -1){
            arr[str[i]] = i;
        }
        else{
            res = min(fi, res);
        }
    }
    
    if(res == INT_MAX){
        cout << -1;
    }
    else{
        cout << res;
    }

    cout << "\n";

    return 0;
}