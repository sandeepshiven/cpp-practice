// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to print the maximum contiguous subarray sum ending at each 
    //position in the array and return the overall maximum.
    long long maximumSum(int arr[], int n)
    {
       vector<long long> dp(n, 0);
       dp[0] = arr[0];
       long long maxi = dp[0];
       cout << dp[0] << " ";
       for(int i=1; i<n; i++){
           dp[i] = max(dp[i-1]+arr[i], (long long)arr[i]);
           cout << dp[i] << " ";
           maxi = max(maxi, dp[i]);
       }
       cout << '\n';
       return maxi;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking total testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking size of array
	    int sizeOfArray;
	    cin>>sizeOfArray;
	    
	    int arr[sizeOfArray];
	    
	    //inserting elements to the array
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    Solution ob;
	    //calling function maximumSum()
	    cout<<ob.maximumSum(arr,sizeOfArray)<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends