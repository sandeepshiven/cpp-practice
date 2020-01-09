#include<bits/stdc++.h>


using namespace std;


int main(){

    cout << "Enter a number to find floor of square root: ";
    int num;
    cin >> num;

    if(num == 0 || num == 1){
        cout << "Ans: " << num << '\n';
    }
    int ans; 
    int start = 1, end = num;

    while(start <= end){
        int mid = (start+end)/2;

        if(mid*mid == num){
            ans = mid;
            break;
        }
        else if(mid*mid < num){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid-1;
        }
    }
    cout << "Ans: " << ans << '\n';

    return 0;

}














