//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9 + 7;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n + 1,vector<int>(sum + 1,-1));
        return solve(arr,n,0,sum,dp);
	}
	int solve(int arr[],int n,int i, int sum,vector<vector<int>> &dp){
	    if(sum == 0){
	        int ans = 1;
	        for(int j = i;j < n;j++){
	            if(arr[j] == 0){
	                ans++;
	            }
	        }
	        return ans;
	    }
	    if(i == n) return 0;
	    if(dp[i][sum] != -1) return dp[i][sum];
	    int pick = 0;
	    if(sum - arr[i] >= 0) pick = solve(arr,n,i + 1, sum - arr[i],dp);
	    int not_pick = solve(arr,n,i + 1, sum, dp);
	    
	    return dp[i][sum] = (pick + not_pick)%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends