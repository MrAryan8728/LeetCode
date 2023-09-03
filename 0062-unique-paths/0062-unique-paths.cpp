class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // return solve(m-1,n-1,dp);
        dp[m-1][n-1] = 1;
        for(int i = m-1;i >= 0;i--){
            for(int j = n-1;j >= 0;j--){
                if(i == m-1 and j == n-1){
                    continue;
                }
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    int solve(int m,int n,vector<vector<int>>&dp){
        if(n == 0 and m == 0) return 1;
        if(n < 0 or m < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        return dp[m][n] = solve(m-1,n,dp)+solve(m,n-1,dp);
    }
};