#include <bits/stdc++.h>
using namespace std;


int main(){
    int s;
    cout << "Enter the size of the array: ";
    cin >> s;
    vector<int> arr(s), table(10000000);
    cout << "Enter the elements of the array: ";
    for(auto i=arr.begin(); i != arr.end(); i++){
        cin >> *i;
        table[*i]++; 
    }
    s=0;
    for(auto i=table.begin(); i != table.end(); i++){
        
        if(*i >= 1){
          s++;  
        } 
    }
    cout << "There are "<<s<<" disticnt elements\n";
    return 0;
}




















