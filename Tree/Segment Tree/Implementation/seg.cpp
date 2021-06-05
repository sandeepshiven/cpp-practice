#include <bits/stdc++.h>
using namespace std;

class SegTree{
    private:
        int sz;
        vector<int>arr;
        vector<int>tree;
        int constructST(int ss, int se, int si);
    public:

        int getSum(int ss, int se);

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

int main(){
    
    return 0;
}