#include<bits/stdc++.h>

using namespace std;

int main(){

    double n,temp;
    int s=0;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<double>arr(n);
    cout << "Enter the elements of array: ";

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }


    priority_queue<double>sm;
    priority_queue<double, vector<double>, greater<double>>gr;

    sm.push(arr[0]);
    cout << sm.top()<<" ";
    for(int i=1; i<n; i++){
        temp = arr[i];
        if(sm.size() > gr.size()){
            if(sm.top() > temp){
                gr.push(sm.top());
                sm.pop();
                sm.push(temp);
            }
            else{
                gr.push(temp);
            }
            cout << (sm.top() + gr.top())/2.0 << " ";
        }
        else{
            if(temp <= sm.top()){
                sm.push(temp);
            }
            else{
                gr.push(temp);
                sm.push(gr.top());
                gr.pop();
            }
            cout << sm.top()<<" ";
        }
        
    }
    cout << "\n";


    return 0;
}