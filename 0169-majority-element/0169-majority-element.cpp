class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0,ans = -1;
        for(int i = 0;i < nums.size();i++){
            if(count == 0) ans = nums[i];

            count += (nums[i] == ans)?1:-1;
        }
        return ans;
    }
};