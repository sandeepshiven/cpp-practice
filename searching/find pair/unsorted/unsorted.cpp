#include<bits/stdc++.h>

using namespace std;
int *find_pair(vector<int> &vec, vector<int> &hash, int ele, int n);
int find_large(vector<int> &vec);
int arr[] = {-1, -1};

int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    vector<int> arr(size);
    for(auto i = arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }
    int largest = find_large(arr);

    vector<int> hashtable(largest*2);
    // for(auto i: hashtable)
    //     cout << i;
    for(auto i : arr)
        hashtable[i] = 1;
    
    int num;
    cout << "Enter the no. to find its sum pair: ";
    cin >> num;
    int *ans = find_pair(arr, hashtable, num, size);
    if(ans[0] != -1 && ans[1] != -1){
        cout << "The pair is: (" << ans[0] << ',' << ans[1] << ")\n";
    }
    else{
        cout << "No pair present\n";
    }

    return 0;
}
int find_large(vector<int> &vec){
    int temp = vec[0];
    for(auto i : vec){
        if(i>temp){
            temp = i;
        }
    }
    return temp;
}

int *find_pair(vector<int> &vec, vector<int> &hash, int ele, int n){

    
    for(auto i: vec){
        if(hash[ele-i] == 1){
            arr[0] = i;
            arr[1] = ele-i;
            break;
        }
    }
    return arr;

}















