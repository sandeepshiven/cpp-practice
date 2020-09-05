#include<bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter the string: ";
    string str;
    cin >> str;
    int arr[256];
    fill(arr, arr+256, -1);

    for(int i=0; i<str.length(); i++){
        if(arr[str[i]] == -1){
            arr[str[i]] = i;
        }
        else{
            arr[str[i]] = -2;
        }
    }
    int res= INT_MAX;
    for(int i=0; i<256; i++){
        if(arr[i] >= 0){
            res = min(res, arr[i]);
        }
    }
    res == INT_MAX? cout<<-1: cout<<res;
    return 0;
}