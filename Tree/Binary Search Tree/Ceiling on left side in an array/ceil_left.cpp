#include<bits/stdc++.h>

using namespace std;

int main(){


    int s, t;
    cout << "Enter the size of array: ";
    cin >> s;
    vector<int>v(s);
    set<int>mySet;

    cout << "Enter the elements of array: ";
    for(int i=0; i<s; i++){
        cin >> t;
        mySet.insert(t);
        auto it = mySet.lower_bound(t);
        if(it == mySet.end()){
            v[i] = -1;
        }
        else{
            v[i] = *it;
        }
    }

    for(auto i: v){
        cout << i<< " ";
    }
    cout << '\n';

    return 0;
}