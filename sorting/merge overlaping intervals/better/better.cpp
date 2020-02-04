#include<bits/stdc++.h>

using namespace std;

void merge_range(vector<pair<int, int> > &arr, int n);



int main(){

    cout << "Enter the number of ranges: ";
    int n;
    cin >> n;
    vector<pair<int, int> >arr(n);

    for(int i=0; i<n; i++){
        cout<<"Enter pair "<<i<<": ";
        cin >>arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    merge_range(arr, n);

    // for(auto i : arr){
    //     cout << i.first << " " << i.second<<endl;
    // }


    return 0;
}

void merge_range(vector<pair<int, int> > &arr, int n){

    int res = 0;

    for(int i=0; i<n; i++){

        if(arr[res].second >= arr[i].first){
            arr[res].second = max(arr[res].second, arr[i].second);
            arr[res].first = min(arr[res].first, arr[i].first);
        }

        else{
            res++;
            arr[res]  = arr[i];
        }
    }

    for(int i=0; i<=res; i++){
        cout << arr[i].first << " "<< arr[i].second << endl;
    }



}

































