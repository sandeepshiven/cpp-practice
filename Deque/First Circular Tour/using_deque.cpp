#include<bits/stdc++.h>

using namespace std;




int findStart(vector<int>&petrol, vector<int>&dist, int n){

    int curr_petrol=0;
    deque<int>dq;
    int i=0;
    while(dq.size() != n){
        
        if(curr_petrol<0 && !dq.empty()){
            curr_petrol -= petrol[dq.front()]-dist[dq.front()];
            dq.pop_front();
        }else{
            curr_petrol += petrol[i%n]-dist[i%n];
            dq.push_back(i%n);
            i++;
        }
        
        
    }
    return (curr_petrol>=0)?dq.front()+1:-1;
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