#include<bits/stdc++.h>

using namespace std;
int count_and_merge(vector<int> &vec, int l, int m, int r);
int count_invertion(vector<int> &vec, int l, int r);



int main(){

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    cout << "Enter the elements of the array: ";

    vector<int> arr(size);
    for(auto i = arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    cout << count_invertion(arr,0, size-1);

    
    cout << '\n';

    return 0;

}

int count_invertion(vector<int> &vec, int l, int r){

    int res = 0;
    if(l<r){
        int mid = (l+r)/2;
        res += count_invertion(vec, l, mid);
        res += count_invertion(vec, mid+1, r);
        res += count_and_merge(vec, l, mid, r);
    }
    return res;

}


int count_and_merge(vector<int> &vec, int l, int m, int r){

    int l_size = m-l+1;
    int r_size = r-m;
    int left[l_size], right[r_size];

    for(int i=0; i<l_size; i++){
        left[i] = vec[l+i];
    }
    for(int i=0; i<r_size; i++){
        right[i] = vec[m+1+i];
    }

    int s1 = 0, s2 = 0, s3 =l, ans = 0;
    while(s1 != l_size && s2 != r_size){
        if(left[s1] <= right[s2]){
            vec[s3++] = left[s1++];
        }
        else{
            vec[s3++] = right[s2++];
            ans += l_size - s1;
        }
    }
    if(s1 == l_size && s2 != r_size){
        while(s2 != r_size){
            vec[s3++] = right[s2++];
        }
    }

    if(s2 == r_size && s1 != l_size){
        while(s1 != l_size){
            vec[s3++] = left[s1++];
        }
    } 

    return ans;

}












