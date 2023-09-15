//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = accumulate(arr,arr + N,0);
        if(sum % 2 == 1) return 0;
        
        vector<vector<int>> dp(sum/2 + 1,vector<int>(N+1,-1));
        
        int get = solve(sum/2,arr,N-1,dp);
        if(get == 0) return 0;
        return 1;
    }
    int solve(int target,int arr[],int i,vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(i < 0) return 0;
        if(dp[target][i] != -1) return dp[target][i];
        int pick = 0;
        if(target - arr[i] >= 0) pick = solve(target-arr[i],arr,i-1,dp);
        int not_pick = solve(target,arr,i-1,dp);
        return dp[target][i] = pick + not_pick;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends