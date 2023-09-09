class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1)); // Fix: Change the size of the second dimension to n
        return solve(nums,0,-1,dp);
    }
    
    int solve(vector<int> &nums,int i,int prev,vector<vector<int>> &dp){
        if(i >= nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1]; // Fix: Adjust the indices for dp
        int not_pick = solve(nums,i+1,prev,dp);
        int pick = 0;
        if(prev == -1 or nums[i] > nums[prev]){
            pick = 1 + solve(nums,i+1,i,dp);
        }
        return dp[i][prev+1] = max(pick,not_pick); // Fix: Adjust the indices for dp
    }
};