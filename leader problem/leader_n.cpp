#include<iostream>
void find_leaders(int *, int);


using namespace std;

int main(){
    int size,pos;
    cout << "Enter the size of the array"<<"\n";
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<< " elements of the array"<<endl;
    for(int i=0; i<size; i++){
        
        cin >> arr[i];
    }
    find_leaders(arr,size);
    cout << '\n';
    return 0;
}

void find_leaders(int a[], int n){
    int cur_lead = a[n-1];
    cout << cur_lead<<' ';
    for(int i=n-2; i>=0;i--){
        if(a[i] > cur_lead){
            cur_lead = a[i];
            cout << cur_lead <<' ';
        }
    }


}