#include<bits/stdc++.h>

using namespace std;
void my_union(vector<int> &, int , vector<int> &, int );



int main(){

    cout << "Enter the size of first array: ";
    int s1;
    cin >> s1;
    cout << "Enter the elements of first array: ";
    vector<int> arr1(s1);
    for(auto i = arr1.begin(); i != arr1.end(); i++){
        cin >> *i;
    }
    
    cout << "Enter the size of second array: ";
    int s2;
    cin >> s2;
    cout << "Enter the elements of second array: ";
    vector<int> arr2(s2);
    for(auto i = arr2.begin(); i != arr2.end(); i++){
        cin >> *i;
    }

    my_union(arr1, s1, arr2, s2);
    cout << '\n';

    return 0;
}


void my_union(vector<int> &arr1, int s1, vector<int> &arr2, int s2){

    int i=0, j=0;

    while(i<s1 && j<s2){

        if(i>0 && arr1[i]==arr1[i-1]){
            i++;
            continue;
        }
        if(j>0 && arr2[j]==arr2[j-1]){
            j++;
            continue;
        }
        if(arr1[i] < arr2[j]){
            cout << arr1[i] << " ";
            i++;
        }
        else if(arr1[i] > arr2[j]){
            cout << arr2[j] << " ";
            j++;
        }
        else{
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    while(i<s1){
        if(i>0 && arr1[i]==arr1[i-1]){
            i++;
            continue;
        }
        else{
            cout << arr1[i] << " ";
            i++;
        }
    }

    while(j<s2){
        if(j>0 && arr2[j]==arr2[j-1]){
            j++;
            continue;
        }
        else{
            cout << arr2[j] << " ";
            j++;
        }
    }

}
















