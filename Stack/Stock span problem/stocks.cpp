#include<bits/stdc++.h>

using namespace std;

void printSpan(vector<int> &arr, int n){

    stack<int>s;
    s.push(0);
    cout << 1 << " ";
    for(int i = 1; i<n; i++){
        while(!(s.empty()) && (arr[s.top()] <= arr[i])){
            s.pop();
        }
        int span = (s.empty()==true)? i+1: i - s.top();
        cout << span << " ";
        s.push(i);
    }
    cout << '\n';


}



int main(){

    cout << "Enter the number of entries: ";
    int s;
    cin >>s;
    vector<int>vec(s);
    cout << "Enter "<<s<<" entries of stock: ";
    for(auto i=vec.begin(); i != vec.end(); i++){
        cin >> *i;
    }
    for(auto i=vec.begin(); i != vec.end(); i++){
        cout << *i <<" ";
    }
    cout << '\n';
    printSpan(vec, s);


    return 0;
}