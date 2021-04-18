#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n, prof, dead, res=0;
    
    cout << "Enter the no. of job: ";
    cin >> n;
    
    vector<pair<string, pair<int, int>>>arr;
    
    for(int i=0; i<n; i++){
        cout << "Enter profit and deadline of job "<< i <<": ";
        cin >> prof >> dead;
        arr.push_back({"J"+to_string(i), {prof, dead}});
    }

    sort(arr.begin(), arr.end(), [](pair<string, pair<int, int>>p1, pair<string, pair<int, int>>p2)->bool{

        return p1.second.first > p2.second.first;
    
    });

    // for(auto i: arr){
    //     cout << i.first << " " << i.second.first << " " << i.second.second;
    //     cout << '\n';
    // }
    auto m = (*max_element(arr.begin(), arr.end(), [](pair<string, pair<int, int>>p1, pair<string, pair<int, int>>p2)->bool{
        return p1.second.second < p2.second.second;
    })).second.second;
    //cout << "Max: " << m;
    vector<string>jobs(m+1, "nill");

    for(int i=0; i<n; i++){
        int d = arr[i].second.second;
        for(int j=d; j>0; j--){
            if(jobs[j] == "nill"){
                jobs[j] = arr[i].first;
                res += arr[i].second.first;
                break;
            }
        }
    }
    cout << "The optimal job sequence is: ";
    for(auto i=1; i<=m; i++){
        cout << jobs[i] << " ";
    }
    cout << "\nAnd total profit is: "<< res;
    cout << '\n';
    return 0;
} 