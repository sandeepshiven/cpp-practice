#include<bits/stdc++.h>

using namespace std;

void printPreviousGreater(vector<int> &arr, int n){

    stack<int>s;
    s.push(arr[0]);
    cout << -1 << " ";
    for(int i = 1; i<n; i++){
        while(!(s.empty()) && (s.top() <= arr[i])){
            s.pop();
        }
        if(s.empty()==true){
            cout << -1<< " ";
        }
        else{
            cout << s.top() << " ";
        }
        
        s.push(arr[i]);
    }
    cout << '\n';


}



int main(){

    cout << "Enter the number of entries: ";
    int s;
    cin >>s;
    vector<int>vec(s);
    cout << "Enter "<<s<<" entries of: ";
    for(auto i=vec.begin(); i != vec.end(); i++){
        cin >> *i;
    }
    for(auto i=vec.begin(); i != vec.end(); i++){
        cout << *i <<" ";
    }
    cout << '\n';
    printPreviousGreater(vec, s);


    return 0;
}