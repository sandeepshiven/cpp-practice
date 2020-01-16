#include<bits/stdc++.h>

using namespace std;
void intersection(vector<int> &arr1, int s1, vector<int> &arr2, int s2);



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

    intersection(arr1, s1, arr2, s2);
    cout << '\n';

    return 0;
}


void intersection(vector<int> &arr1, int s1, vector<int> &arr2, int s2){

    int i=0, j=0;

    while(i<s1 && j<s2){

        if(i>0 && arr1[i]==arr1[i-1]){
            i++;
            continue;
        }

        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else{
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }


}
















