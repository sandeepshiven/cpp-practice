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
    
    for(int i =0; i<d; i++){
        int temp = a[0];
        for(int j=0; j<n-1; j++){
            a[j]=a[j+1];
        }
        a[n-1] = temp;
    }
}



















