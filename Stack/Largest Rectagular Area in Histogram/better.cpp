#include<bits/stdc++.h>

using namespace std;

void fillPreviousSmaller(vector<int>&arr, vector<int>&ps, int n){
    
    stack<int>s;
    s.push(0);
    ps[0]=-1;
    for(int i=1; i<n; i++){

        while(!(s.empty()) && arr[s.top()] >= arr[i]){
            s.pop();
        }

        ps[i] = (s.empty())? -1: s.top();

        s.push(i);
    }
}

void fillNextSmaller(vector<int>&arr, vector<int>&ns, int n){

    stack<int>s;
    s.push(n-1);
    ns[n-1] = n;
    
    for(int i=n-2; i>=0; i--){
        while(!(s.empty()) && arr[s.top()] >= arr[i] ){
            s.pop();
        }
        ns[i] = (s.empty())?n:s.top();
        s.push(i);
    }

}



int findLargestArea(vector<int>&arr, int n){

    int res = 0;

    vector<int>ps(n);
    vector<int>ns(n);

    fillPreviousSmaller(arr, ps, n);
    fillNextSmaller(arr, ns, n);
    

    for(int i=0; i<n; i++){
        
        int current = arr[i];

        current += (i-ps[i]-1)*arr[i];
        current += (ns[i]-i-1)*arr[i];

       
        res = max(res, current);

    }
    return res;

}









int main(){

    cout << "Enter the number of bars: ";
    int s;
    cin >> s;
    vector<int>vec(s);
    cout << "Enter the values of "<<s<<" bars: ";
    for(auto i=vec.begin(); i!=vec.end(); i++){
        cin >> *i;
    }
    cout << "Largest area is: "<<findLargestArea(vec, s)<<'\n';


    return 0;
}