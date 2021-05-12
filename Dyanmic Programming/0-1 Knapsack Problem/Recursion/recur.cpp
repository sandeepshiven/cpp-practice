#include <bits/stdc++.h>
using namespace std;

void fillSack(vector<pair<int, int>>&arr, int n, int w, int index, int &res, pair<int, int>&bag){

    if(bag.second > w || index <0){
        return;
    }
    else{
        res = max(res, bag.first);
    }
    bag.first += arr[index].first;
    bag.second += arr[index].second;
    fillSack(arr, n, w, index-1, res, bag);
    bag.first -= arr[index].first;
    bag.second -= arr[index].second;
    fillSack(arr, n, w, index-1, res, bag);

}


int main(){

    int n, w;
    
    cout << "Enter number of items: ";
    cin >> n;
    vector<pair<int, int>>arr(n);
    for(int i=0; i<n; i++){
        cout << "Enter value and weight of item" << i+1 << ": "; 
        cin >> arr[i].first >> arr[i].second;
    }

    cout << "Enter max weight: ";
    cin >> w;
    int res=-1;
    pair<int, int>bag(0, 0);
    fillSack(arr, n, w, n-1, res, bag);
    cout << "Result: " << res << '\n';

    return 0;
}