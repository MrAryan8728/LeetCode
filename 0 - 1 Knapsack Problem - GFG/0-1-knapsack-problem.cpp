//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(W+1,vector<int>(n+1,-1));
       return KnapSack(W,wt,val,n,dp);
    }
    int KnapSack(int W, int wt[], int val[],int n,vector<vector<int>> &dp){
         if(n == 0 or W == 0) return 0;
         if(dp[W][n] != -1) return dp[W][n];
        
        if(wt[n-1] <= W){
            int pick = val[n-1] + KnapSack(W-wt[n-1],wt,val,n-1,dp);
            int not_pick = KnapSack(W,wt,val,n-1,dp);
            return max(pick,not_pick);
        }
        
        return dp[W][n] = KnapSack(W,wt,val,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends