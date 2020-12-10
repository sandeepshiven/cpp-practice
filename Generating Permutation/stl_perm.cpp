#include<bits/stdc++.h>

using namespace std;

void search(int n, vector<int>&permutation, vector<bool>&chosen){
    if(permutation.size() == n){
        for(int x: permutation){
            cout << x << " ";
        }
        cout << '\n';
    }
    else{
        for(int i=1; i<=n; i++){
            if(chosen[i]){
                continue;
            }
            chosen[i] = true;
            permutation.push_back(i);
            search(n, permutation, chosen);
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main(){

    cout << "Enter the no. of elements: ";
    int n;
    cin >> n;
    vector<int>permutation;
    for(int i=1; i<=n; i++){
        permutation.push_back(i);
    }

    do{
        for(int x: permutation){
            cout << x << ' ';

        }
        cout << '\n';
    }while(next_permutation(permutation.begin(), permutation.end()));
    

    return 0;
}