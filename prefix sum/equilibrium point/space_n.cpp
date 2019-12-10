 
#include <bits/stdc++.h>
using namespace std;

void suffix_array(int*,int *,int);
void prefix_array(int*,int *,int);
bool find_equil(int*, int);

int main(){
    cout<<"Enter the size of the array: ";
    int size,start, end;
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<<" elements of the array\n";
    for(int i=0; i<size;i++)
       cin >> arr[i];
    if(find_equil(arr,size))
        cout << "Yes"<<'\n';
    else
        cout << "No"<<'\n';   
    
    return 0;

}

bool find_equil(int a[], int n){
    int pre_arr[n+1], suf_arr[n+1];
    prefix_array(a,pre_arr,n);
    suffix_array(a,suf_arr,n);
    for(int i=1; i<=n; i++){
        if(pre_arr[i-1]==suf_arr[i])
            return true;
    }
    return false;
}


void prefix_array(int a[],int p[], int n){
    
    p[0]=0;
    for(int i=1; i<=n; i++){
        p[i] = a[i-1]+p[i-1];
    }
    for(int i=0; i<=n; i++){
        cout<<p[i]<<" ";
    }
    cout <<'\n';
    
}

void suffix_array(int a[],int s[], int n){
    
    s[n]=0;
    for(int i=n-1; i>=0; i--){
        s[i] = a[i]+s[i+1];
    }
    for(int i=0; i<=n; i++){
        cout<<s[i]<<" ";
    }
    cout <<'\n';
    
}



