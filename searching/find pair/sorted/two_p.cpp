#include<bits/stdc++.h>


using namespace std;
int *find_pair(vector<int> &vec, int num, int n);

int arr[] = {-1, -1};


int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";

    vector< int> arr(size);
    for(auto i = arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    cout << "Enter the no. to find sum pair: ";
    int num;
    cin >> num;
    int *ans = find_pair(arr, num, size);
    if(ans[0] != -1 && ans[1] != -1){
        cout << "The pair is: (" << ans[0] << ',' << ans[1] << ")\n"; 
    }
    else{
        cout << "No pair present\n";
    }
    return 0;

}


int *find_pair(vector<int> &vec, int num, int n){
    int left = 0, right = n-1;
    while(left != right){
        if(vec[left]+vec[right] == num){
            arr[0] = vec[left];
            arr[1] = vec[right];
            break;
        }
        else if(vec[left]+vec[right] > num){
            right--;
        }
        else{
            left++;
        }
    }
    return arr;
}













