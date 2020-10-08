#include<bits/stdc++.h>

using namespace std;

void printNextGreater(vector<int> &arr, int n){

    stack<int>s;
    vector<int>store(n);
    s.push(arr[n-1]);
    store[n-1] = -1;
    for(int i = n-2; i>=0; i--){
        while(!(s.empty()) && (s.top() <= arr[i])){
            s.pop();
        }
        if(s.empty()==true){
            store[i] = -1;
        }
        else{
            store[i] = s.top();
        }
        
        s.push(arr[i]);
    }

    for(auto i=store.begin(); i!=store.end(); i++){
        cout << *i << " ";
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
    printNextGreater(vec, s);


    return 0;
}