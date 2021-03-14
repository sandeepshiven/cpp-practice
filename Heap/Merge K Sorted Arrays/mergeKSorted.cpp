#include<bits/stdc++.h>

using namespace std;

class Triplet{
    public:
        int val, oPos, inPos;
        Triplet(int v, int p, int i){
            val = v;
            oPos = p;
            inPos = i;
        }
};

struct MyComp{

    bool operator()(Triplet &p1, Triplet &p2){
        return p1.val > p2.val;
    }
};


vector<int> mergeArrays(vector<vector<int>>&arr){

    vector<int>res;
    priority_queue<Triplet, vector<Triplet>, MyComp>pq;
    for(int i=0; i<arr.size(); i++){
        Triplet t(arr[i][0], i, 0);
        pq.push(t);
    }

    while(!pq.empty()){
        Triplet curr = pq.top();
        pq.pop();
        res.push_back(curr.val);
        int op = curr.oPos;
        int in = curr.inPos;
        if(in+1 < arr[op].size()){
            Triplet t(arr[op][in+1], op, in+1);
            pq.push(t);
        }
    }
    return res;

}



int main(){

    int n, m;
    cout << "Enter the number of array: ";
    cin >> n;
    vector<vector<int>>arr;
    for(int i=0; i<n; i++){
        cout << "Enter the size of array "<< i+1 << ": ";
        cin >> m;
        cout << "Enter the elements of array "<< i+1 << ": ";
        vector<int> temp(m);
        for(int j=0; j<m; j++){
            cin >> temp[j];
        }
        arr.push_back(temp);
    }

    vector<int> vc = mergeArrays(arr);

    for(auto i: vc){
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}