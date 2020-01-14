#include<bits/stdc++.h>


using namespace std;
int *find_triplet(vector<int> &vec, int num, int n);
int arr[] = {-1, -1, -1};

int main(){

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";
    vector<int> arr(size);
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }
    sort(arr.begin(), arr.end());
    int num;
    cout << "Enter the no. to find the triplet: ";
    cin >> num;
    int *ans = find_triplet(arr, num, size);
    if(ans[0] != -1 && ans[1] != -1 && ans[2] != -1){
        printf("The triplet is: (%d, %d, %d)\n", ans[0], ans[1], ans[2]);
    }
    else{
        cout << "No triplet found\n";
    }

    return 0;

}


int *find_triplet(vector<int> &vec, int num, int n){

    for(int i=0; i<n; i++){

        int left = i+1, right = n-1;
        
        while(left != right){
            if(vec[i]+vec[left]+vec[right] == num){
                arr[0] = vec[i];
                arr[1] = vec[left];
                arr[2] = vec[right];
                return arr;
            }
            else if(vec[i]+vec[left]+vec[right] > num){
                right--;
            }
            else{
                left++;
            }
        }

    }
    return arr;
}

















































