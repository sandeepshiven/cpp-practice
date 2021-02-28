#include<bits/stdc++.h>

using namespace std;

int main(){

    cout << "Enter the size of the array: ";
    int s;
    cin >> s;
    cout << "Enter the elements of the array: ";
    vector<int> v(s);
    for(int i=0; i<s; i++){
        cin >> v[i];
    }
    cout << "The elements needed to be swapped: ";
    int prev = INT_MIN, first = INT_MIN, second= INT_MIN;
    for(auto i: v){
        if(prev > i){
            if(first == INT_MIN)
                first = prev;
            second = i;
        }
        prev = i;
    }
    cout << first << " " << second << "\n";

    return 0;
}