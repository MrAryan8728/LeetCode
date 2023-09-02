class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = 0,j = 0,k = n-1;
        //i and j start par and k end par:
        //1 par j++:
        //0 par swap i++ and j++:
        //2 par swap j and k--:
        while(j <= k){
            if(nums[j] == 1) j++;
            else if(nums[j] == 0) swap(nums[i++],nums[j++]);
            else swap(nums[j],nums[k--]);
        }
    }

    //Easy Solution: sort(nums.begin(),nums.end());
};