#include <bits/stdc++.h>
using namespace std;

int maxprofit(int *,int, int);


int main(){
    cout<<"Enter the size of the array: ";
    int size;
    cin >>size;
    int arr[size];
    cout << "Enter "<<size<<" elements of the array\n";
    for(int i=0; i<size;i++)
       cin >> arr[i];
    cout << "The maximum profit is: "<<maxprofit(arr,0,size-1)<<'\n';
    return 0;

}

int maxprofit(int a[], int start, int end){
    
    if(end<=start)
        return 0;
    int profit=0;
    int currprof;
    for(int i=start; i<end; i++){
        for(int j=i+1; j<=end; j++){
            if(a[j]>a[i]){
                currprof = a[j]-a[i]+maxprofit(a,j+1,end)+maxprofit(a,start,i-1);
                profit = max(profit,currprof);
            }

        }
    }
    return profit;
}

