#include<iostream>
void rotate(int *, int ,int);


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
    int temp[d];
    for(int i=0; i<d; i++)
        temp[i]=a[i];
    for(int i =d; i<n; i++)
        a[i-d] = a[i];
    for(int i =0; i<d; i++)
        a[n-d+i] = temp[i];
    
}







