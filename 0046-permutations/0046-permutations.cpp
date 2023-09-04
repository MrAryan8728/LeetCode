class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
         solve(ans,nums,0);
          return ans;
    }
    void solve(vector<vector<int>> &ans,vector<int> &nums,int ind){
        if(ind >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i = ind;i < nums.size();i++){
            //Generating permuations.
            swap(nums[i],nums[ind]);
            solve(ans,nums,ind+1);
            //Backtracking the change. 
            swap(nums[i],nums[ind]);
        }
    }
};