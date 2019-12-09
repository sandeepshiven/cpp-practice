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
    for(int i=0; i<n;i++){
        bool flag = false;
        for(int j=i+1; j<n; j++){
            if(a[i] <= a[j])
                flag = true;
        }
        if(flag == false)
            cout <<a[i]<<' ';
    }


}