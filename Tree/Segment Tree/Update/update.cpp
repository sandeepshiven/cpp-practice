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
        void update(int ss, int se, int i, int si, int diff);


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

void SegTree::update(int ss, int se, int i, int si, int diff){
    if(i > se || i < ss){
        return ;
    }
    tree[si] = tree[si] + diff;
    if(se > ss){
        int mid = (ss+se)/2;
        update(ss, mid, i, (2*si)+1, diff);
        update(mid+1, se, i, (2*si)+2, diff);
    }
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
    while (1){
        int choice;
        cout << "1. getsum\n2. update\n";
        cin >> choice;
        switch (choice)
        {
            case 1:{

                int x, y;
                cout << "Enter range: ";
                cin >> x >> y;
                cout << segT.getSum(x, y, 0, n-1, 0) << '\n';
                break;
            }
            case 2:{

                int i, new_val;
                cout << "Enter index and new val: ";
                cin >> i >> new_val;
                int diff = new_val - arr[i];
                segT.update(0, n-1, i, 0, diff);
                break;
            }
            
            default:
                break;
        }
    }
    
    
    
    

    return 0;
}