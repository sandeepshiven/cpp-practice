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

    int new_low = arr[0].first, new_high = arr[0].second, i=1;

    while(i<n){

        if(new_high >= arr[i].first){
            if(arr[i].second > new_high){
                new_high = arr[i].second;
            }
            i++;
        }
        else{
            cout << new_low << " " << new_high<<endl;
            new_low = arr[i].first;
            new_high = arr[i].second;
            i++;
        }



    }

    cout << new_low << " " << new_high<<endl;



}






































