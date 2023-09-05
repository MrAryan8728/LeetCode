/*
We can solve this question using 3 ways.

    1.Find all the permutation of Array(nums) then we can easily find next permutation.
    2.Solved using Array + Two Pointers.
    3.Solved using next_permutation (inbuilt) function.

    Algo:
    * find the break point.
    * if break point is initial the reverse the whole.
    * else find the value just greater than the breakpoint
    * swap with that and Reverse the bp + 1 to end.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(),ind = -1;
        for(int i = n-2;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                ind = i;
                break;
            }
        }
        if(ind == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i = n-1;i >= ind;i--){
                if(nums[i] > nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            reverse(nums.begin()+ind+1,nums.end());
        }
    }
};