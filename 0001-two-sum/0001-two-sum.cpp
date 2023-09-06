class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        //Brute-force.
        // for(int i = 0;i < n;i++){
        //     for(int j = i+1;j < n;j++){
        //         if(nums[i]+nums[j] == target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //         }
        //     }
        // }
        // return ans;

        // Better 
        unordered_map<int,int> mp;

        for(int i = 0;i < n;i++){
            if(mp.find(target-nums[i]) != mp.end()){
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]] = i;
        }

        return {};
    }
};