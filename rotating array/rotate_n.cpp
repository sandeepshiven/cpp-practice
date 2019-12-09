#include<iostream>
void rotate(int *, int ,int);
void reverse(int *, int, int );

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
    
    cout<<"Enter no. of position you want to rotate"<<'\n';
    cin >> pos;
    rotate(arr,size,pos);
    for(int i=0; i<size; i++)
        cout << arr[i]<<" ";
    cout << '\n';
    return 0;
}


void rotate(int a[], int n, int d){
    reverse(a,0,d-1);
    reverse(a,d,n-1);
    reverse(a,0,n-1);
}

void reverse(int a[], int n ,int d){
    while(n<d){
       int temp = a[n];
        a[n] = a[d];
        a[d] = temp;
        n++;
        d--;
    }
}


