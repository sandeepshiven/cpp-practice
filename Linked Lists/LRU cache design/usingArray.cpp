#include<bits/stdc++.h>

using namespace std;

bool miss(int n, vector<int>&vec){
    for(int i: vec){
        if(i==n){
            return false;
        }
    }
    return true;
}






int main(){

    int s;
    cout << "Enter the size of cache: ";
    cin >> s;
    vector<int>cache(s,-1);
    cout << "Enter reference sequence size: ";
    int temp;
    cin >> temp;

    vector<int>vec(temp);

    cout << "Enter reference sequence: ";

    for(int i=0; i<temp; i++){
        cin >> vec[i];
    }

    int currPos = 0;

    for(auto i: vec){
        
        if(miss(i, vec)){
            if(currPos < s){
                cache[currPos] = i;
                currPos++;
            }
            
        }

    }


    return 0;
}