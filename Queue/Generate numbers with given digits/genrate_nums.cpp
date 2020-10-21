#include<bits/stdc++.h>

using namespace std;

void generateNumbers(int start, int stop, int out){
    queue<string>q;
    for(int i=start; i<=stop; i++){
        q.push(to_string(i));
    }
    for(int i=0; i<out; i++){
        string curr = q.front();
        cout << curr<<" ";
        q.pop();
        for(int i=start; i<=stop; i++){
            q.push(curr+to_string(i));
        }
        
    }
    cout << '\n';
}

int main(){

    cout << "Enter the start number from 1 to 9: ";
    int start;
    cin >> start;
    cout << "Enter the stop number from"<<start<<" 9: ";
    int stop;
    cin >> stop;
    cout << "Enter the number of output you want: ";
    int out;
    cin >> out;
    generateNumbers(start, stop, out);
    return 0;
}