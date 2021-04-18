#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, val, wt, cap;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<pair<double, pair<double, double>>>arr;
    for(int i=0; i<n; i++){
        cout << "Enter the weight and value of element no. " << i+1 << ": ";
        cin >> wt >> val;
        arr.push_back({val/wt, {wt, val}});
    }
    cout << "Enter the capacity of knapsack: ";
    cin >> cap;
    sort(arr.begin(), arr.end(), greater<pair<double, pair<double, double>>>());

    double res =0, curr_cap = cap;
    for(int i=0; i<n; i++){
        if(arr[i].second.first <= curr_cap){
            curr_cap -= arr[i].second.first;
            res += arr[i].second.second;
        }
        else{
            res += (arr[i].second.second * (curr_cap/arr[i].second.first));
            break;
        }
    }
    cout << "Ans: " << res << "\n";
    

    return 0;
}