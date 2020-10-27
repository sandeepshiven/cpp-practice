#include<bits/stdc++.h>

using namespace std;




int findStart(vector<int>&petrol, vector<int>&dist, int n){

    int total_petrol=0, extra_petrol=0;
    int index=0;
    for(int i=0; i<n; i++){
        total_petrol += petrol[i] - dist[i];
        extra_petrol += petrol[i] - dist[i];
        if(extra_petrol<0){
            extra_petrol = 0;
            index = i+1;
        }
    }

    return (total_petrol>=0)?index+1:-1;
    

}


int main(){

    cout << "Enter number of petrol pumps: ";
    int n;
    cin >> n;
    cout << "Enter quantity of petrol in "<<n<<" pumps: ";
    vector<int>petrol(n);
    for(int i=0; i<n; i++){
        cin >> petrol[i];
    }
    cout << "Enter distances between "<<n<<" pumps: ";
    vector<int>dist(n);
    for(int i=0; i<n; i++){
        cin >> dist[i];
    }
    cout << "Starting point: "<<findStart(petrol, dist, n)<<'\n';
    return 0;
}