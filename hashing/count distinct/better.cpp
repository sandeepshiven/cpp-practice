#include <bits/stdc++.h>
using namespace std;


int main(){
    int s,temp;
    cout << "Enter the size of the array: ";
    cin >> s;
    unordered_set<int> arr;
    cout << "Enter the elements of the array: ";
    for(int i=0; i < s; i++){
        cin >> temp;
        arr.insert(temp);
    }
    cout<< "There are "<<arr.size()<<" disticnt elements\n";
    // for(auto i: arr){
    //     cout << i << " ";
    // }
    return 0;
}




















