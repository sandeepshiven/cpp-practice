#include <bits/stdc++.h>
using namespace std;

class BITree{

    private: 
        vector<int>arr;
        vector<int>bITree;
        int n;
    
    public:
        int getSum(int i);
        void update(int i, int val);


        BITree(vector<int>a){
            arr = a;
            n = a.size();
            bITree = vector<int>(n+1, 0);
            for(int i=0; i<n; i++){
                int temp = arr[i];
                arr[i] = 0;
                update(i, temp);
            }
        }


};


int BITree :: getSum(int i){
    
    i = i+1;
    int res = 0;
    while(i>0){
        res += bITree[i];
        i = i - (i & (-i));
    }
    return res;
}

void BITree :: update(int i, int val){

    int diff = val - arr[i];
    arr[i] = val;
    i = i+1;
    while(i <= (n)){
        bITree[i] += diff;
        i = i + (i & (-i));
    }
}

int main(){
    
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the elements of array: ";
    vector<int>arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    BITree tree(arr);
    while(1){
        int choice;
        cout << "1. getSum\n2. update\n";
        cin >>choice;
        switch(choice){

            case 1: {
                int i;
                cout << "Enter index to sum: ";
                cin >> i;
                cout << "Prefix Sum: " << tree.getSum(i);
                cout << "\n";
                break;
            }

            case 2: {
                int i, val;
                cout << "Enter index and val: ";
                cin >> i >> val;
                tree.update(i, val);
            }

            default: 
                break;

        }
    }

    return 0;
}