#include <bits/stdc++.h>
using namespace std;

class SegTree{
    private:
        int sz;
        vector<int>arr;
        vector<int>tree;
        int constructST(int ss, int se, int si);
    public:

        int getSum(int qs, int qe, int ss, int se, int si);

        SegTree(vector<int>v){
            arr = v;
            sz = arr.size();
            tree = vector<int>(4*sz);
            constructST(0, sz-1, 0);
        }
};

int SegTree::constructST(int ss, int se, int si){
    
    if(ss == se){
        tree[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss + se)/2;
    tree[si] = constructST(ss, mid, (2*si)+1) + constructST(mid+1, se, (2*si)+2);
    return tree[si];
}

int SegTree::getSum(int qs, int qe, int ss, int se, int si){

    if(se < qs || ss > qe){
        return 0;
    }
    
    if(qs <= ss && qe >= se){
        return tree[si];
    }
    
    int mid = (ss+se)/2;
    return getSum(qs, qe, ss, mid, (2*si)+1) + getSum(qs, qe, mid+1, se, (2*si)+2);

}

int main(){
    
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    SegTree segT(arr);
    cout << segT.getSum(0, 2, 0, n-1, 0) << '\n';
    cout << segT.getSum(1, 3, 0, n-1, 0) << '\n';
    cout << segT.getSum(0, 3, 0, n-1, 0) << '\n'; 

    return 0;
}