//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[]) {
    int sum = accumulate(arr, arr + N, 0);
    if (sum % 2 == 1) return 0;
    int target = sum / 2;
    vector<vector<int>> dp(target + 1, vector<int>(N + 1, 0));

    for (int i = 0; i <= N; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= target; i++) {
        for (int j = N - 1; j >= 0; j--) {
            dp[i][j] = dp[i][j + 1];
            if (i >= arr[j]) {
                dp[i][j] += dp[i - arr[j]][j + 1];
            }
        }
    }

    return dp[target][0] == 0 ? 0 : 1;
    }
    int solve(int target,int i,int arr[],int N,vector<vector<int>> &dp){
        if(target == 0) return 1;
        if(i == N) return 0;
        if(dp[target][i] != -1) return dp[target][i];
        int pick = 0;
        if(target - arr[i] >= 0) pick = solve(target-arr[i],i + 1,arr,N,dp);
        int not_pick = solve(target,i + 1,arr,N,dp);
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