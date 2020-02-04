#include <bits/stdc++.h>
using namespace std;

void seperate(vector<int> &vec, int n, int , int);


int main() {

    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    cout << "Enter the elements of the array: ";

    vector<int> arr(size);
    for(auto i= arr.begin(); i != arr.end(); i++){
        cin >> *i;
    }

    cout << "Enter the range: ";
    int high, low;
    cin  >> low >> high;

    seperate(arr, size, low, high);

    for(auto i: arr)
        cout << i << " ";
    
    cout << '\n';


	return 0;
}



void seperate(vector<int> &arr, int n, int low, int high){

    int l = 0, r=n-1, mid = 0, range;
    while(mid<=r){

        if(arr[mid] < low){
            range = 0;
        }
        else if(arr[mid] > high){
            range = 2;
        }
        else{
            range =1 ;
        }


        switch(range)
        {
            case 0:
                swap(arr[mid], arr[l]);
                l++;
                mid++;
                break;

            case 1:
                mid++;
                break;

            case 2:
                swap(arr[mid], arr[r]);
                r--;
                break;
        
        default:
            break;
        }

        
    }

   

}









































