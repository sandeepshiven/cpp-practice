#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, amount, res=0, curr;

    cout << "Enter the number of coins: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << "Enter the amount: ";
    cin >> amount;

    sort(arr.begin(), arr.end(), greater<int>());

    for(int i=0; i<n; i++){
        if(amount >= arr[i]){
            curr = floor(amount/arr[i]);
            cout << curr << " Coins of: "<<arr[i] << '\n';
            res += curr;
            amount -= (curr*arr[i]);
        }
        if(amount == 0){
            break;
        }
    }
    cout << "Total "<<res << " coins are used.\n";

    return 0;
}