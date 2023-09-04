class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //Edge cases:
        int n = nums.size();
        if(n == 1) return nums[0];
        //Removing extra over-head of the first and last elelment.
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        int l = 1,h = n-1;
        while(l <= h){
            int m = l + (h - l)/2;
            if(nums[m] != nums[m-1] and nums[m] != nums[m+1]){
                return nums[m];
            }
            //Agar even index hai to always agle ke equal hoga 
            //ya fir odd hai to always pichle ke equal hoga
            //Nhi hai to iska mtlb ki wo hamare right half mein hi hoga.
            //Kyonki Left half ki condition not satisfied.
            else if((m % 2 == 0 and nums[m] != nums[m+1]) or 
            (m % 2 == 1 and nums[m] != nums[m-1])){
                h = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return -1;
    }
};