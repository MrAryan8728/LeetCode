class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(0,nums.size()-1,nums,count);
        return count;
    }
    void mergeSort(int l, int h, vector<int> &nums, int &count){
        int m = (l + h)/2;
        if(l >= h) return;
        mergeSort(l, m, nums,count);
        mergeSort(m + 1, h, nums,count);
        merge(l, m, h, nums,count);
    }
    void merge(int l, int m, int h, vector<int> &nums, int &count){
        int left = l;
        int right = m + 1;
        int j = m + 1;
        vector<int> temp;
        for(int i = l;i <= m;i++){
            while(j <= h && nums[i] > 2*(long long )nums[j]){
                j++;
            }
            count += j - (m + 1);
        }
        while(left <= m and right <= h){
            if(nums[left] < nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= m){
            temp.push_back(nums[left]);
            left++;
        }
        while(right <= h){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i = l;i <= h;i++){
            nums[i] = temp[i - l];
        }
    }
};