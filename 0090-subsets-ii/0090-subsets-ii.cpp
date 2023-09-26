class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(ans, nums, temp, 0);
        return ans;
    }

    void solve(vector<vector<int>>& ans, vector<int>& nums, vector<int>& temp, int start) {
        ans.push_back(temp); // Add the current subset to the result

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates to avoid duplicate subsets
            }

            temp.push_back(nums[i]);
            solve(ans, nums, temp, i + 1);
            temp.pop_back();
        }
    }
};
