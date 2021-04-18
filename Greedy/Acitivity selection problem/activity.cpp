#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, start, end;
    cout << "Enter the number of activities: ";
    cin >> n;
    vector<pair<int, int>>arr;
    for(int i=0; i<n; i++){
        cout << "Enter start and end time of activity "<< i+1 << ": ";
        cin >> start >> end;
        arr.push_back({start, end});
    }
    sort(arr.begin(), arr.end(), [](pair<int, int>&a, pair<int, int>&b) -> bool{
        return a.second < b.second;
    });
    int res = 1;
    vector<pair<int, int>>ans;
    ans.push_back(arr[0]);

    for(int i=1, j=0; i<n; i++){
        if(ans[j].second > arr[i].first){
            continue;
        }
        else{
            ans.push_back(arr[i]);
            j++;
            res++;
        }
    }
    cout << "The activities that can be run are: \n";
    for(auto x: ans){
        cout << x.first << " " << x.second << '\n';
    }
    return 0;
}