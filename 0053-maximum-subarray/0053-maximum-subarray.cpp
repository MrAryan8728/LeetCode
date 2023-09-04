class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = 0,maxi =INT_MIN;
        for(int i = 0;i < nums.size();i++){
            ans += nums[i];
            maxi = max(maxi,ans);
            if(ans < 0){
                ans = 0;
            }
        }
        return maxi;
    }
};