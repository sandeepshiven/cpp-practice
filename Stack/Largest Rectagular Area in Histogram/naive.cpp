#include<bits/stdc++.h>

using namespace std;



int findLargestArea(vector<int>&arr, int s){

    int res = 0;
    for(int i=0; i<s; i++){
        
        int current = arr[i];

        for(int j=i-1; j>=0 && arr[j]>=arr[i]; j--){
            current += arr[i];
        }

        for(int j=i+1; j<s && arr[j]>=arr[i]; j++){
            current += arr[i];
        }
        res = max(res, current);

    }
    return res;

}









int main(){

    cout << "Enter the number of bars: ";
    int s;
    cin >> s;
    vector<int>vec(s);
    cout << "Enter the values of "<<s<<" bars: ";
    for(auto i=vec.begin(); i!=vec.end(); i++){
        cin >> *i;
    }
    cout << "Largest area is: "<<findLargestArea(vec, s)<<'\n';


    return 0;
}