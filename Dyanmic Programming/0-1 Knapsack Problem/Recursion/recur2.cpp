#include <bits/stdc++.h>
using namespace std;

int fillSack(vector<pair<int, int>>&arr, int n, int w){

    if(w <=0 || n <= 0){
        return 0;
    }

    if(arr[n].second > w){
        return fillSack(arr, n-1, w);
    }
    else{
        return max(fillSack(arr, n-1, w), arr[n].first + fillSack(arr, n-1, w-arr[n].second));
    }

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
   
    
    cout << "Result: " << fillSack(arr, n-1, w) << '\n';

    return 0;
}