class Solution {
public:
    /*
    Approach
lets take the count = 0 and starting from the first element(nums[0]) of the array which is stored in el variable , we are iterating through the loop. if the elemnts of the array while iterating through the loop is equal to the element stored earlier in it then increase the count by 1 , otherwise decrease it by 1. also , most important while doing this there will be a point when the count ill be zero then in that case the the next element is taken and the count again starts from 1.

given array: [2 2 1 1 2 2]

take el=2

cnt=0->1
the next el is also 2 so again it will increase
cnt=2

now the next el is 1 so it will decrease
el=1 (el changes from 2 to 1)
cnt=1

again decrease
cnt=0 now when is zero the next element we'll get is 2 which will make the count 1 again
and so its goes on.....
    */
    int majorityElement(vector<int>& nums) {
        int count = 0,ans = -1;
        for(int i = 0;i < nums.size();i++){
            if(count == 0) ans = nums[i];

            count += (nums[i] == ans)?1:-1;
        }
        return ans;
    }
};