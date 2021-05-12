#include <bits/stdc++.h>
using namespace std;


int eggDrop(int f, int e){

    int res = INT_MAX;
    if(e==1){
        return f;
    }
    else if(f==1){
        return 1;
    }
    else if(f==0){
        return 0;
    }

    for(int i=1; i<=f; i++){
        res = min(res, max(eggDrop(i-1, e-1), eggDrop(f-i, e)));
    }
    return res+1;

}


int main(){

    int e, f;
    cout << "Enter number of eggs: ";
    cin >>e;
    cout << "Enter number of floors: ";
    cin >>f;
    cout << "Min. trials: " << eggDrop(f, e) << '\n';

    return 0;
}