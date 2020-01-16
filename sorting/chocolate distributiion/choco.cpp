#include<bits/stdc++.h>

using namespace std;
int choco(vector<int> &arr, int n, int c);


int main(){

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    cout << "Enter the elements of the array: ";
    vector<int> arr(size);
    for(auto i = arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    cout << "Enter the number of children: ";
    int nth;
    cin >> nth;

    printf("The minimum difference is: %d\n",choco(arr,size, nth));

    return 0;
}


int choco(vector<int> &arr, int n, int c){
    
    sort(arr.begin(), arr.end());
    int ans = arr[c-1] - arr[0];
    for(int i=1; i<=n-c; i++){
        ans = min(ans , (arr[i+(c-1)]-arr[i]));
    }

    return ans;

}



















