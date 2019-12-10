 
#include <bits/stdc++.h>
using namespace std;

int find_sum (int *,int, int);
void prefix_array(int*,int);

int main(){
    cout<<"Enter the size of the array: ";
    int size,start, end;
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<<" elements of the array\n";
    for(int i=0; i<size;i++)
       cin >> arr[i];
    prefix_array(arr, size);
    char cont = 'y';
    while(cont == 'y'){

    cout << "From which index: ";
    cin >> start;
    cout << "To which index: ";
    cin >> end;
    cout << "The sum form index "<<start<<" to "<<end<<" is: "<<find_sum(arr,start, end)<<'\n';
    cout<<"Do you want to countinue?(y/n): ";
    cin >> cont;

    }
    return 0;

}

void prefix_array(int a[], int n){
    
    for(int i=1; i<n; i++){
        a[i] += a[i-1];
    }
    
}

int find_sum(int a[],int s, int e){
    if(s==0)
        return a[e];
    else
       return (a[e]-a[s-1]);
    
}