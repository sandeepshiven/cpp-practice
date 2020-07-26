#include<bits/stdc++.h>
using namespace std;

int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    unordered_set<int>hashTable;

    vector<int>arr(size);
    
    cout << "Enter the elements of the array: ";

    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
        hashTable.insert(*i);
    }
    
    int res=1, curr = 1;

    for(auto i: arr){
        if(hashTable.find(i-1) == hashTable.end()){
            curr = 1;
            while(hashTable.find(i+curr) != hashTable.end())
            {
                curr++;
            }
            
            res = max(res, curr);
        }
    }
    cout<< res << "\n";




    return 0;
}






















