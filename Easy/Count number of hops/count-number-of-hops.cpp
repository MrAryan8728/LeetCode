//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod = 1000000007;
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        // your code here
        vector<long long> dp(n + 1,-1);
        return solve(n,dp);
    }
    long long solve(int n,vector<long long> &dp){
        if(n < 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 4;
        if(dp[n] != -1) return dp[n];
        return dp[n] = (solve(n-1,dp)%mod + solve(n-2,dp)%mod + solve(n-3,dp)%mod)%mod;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends