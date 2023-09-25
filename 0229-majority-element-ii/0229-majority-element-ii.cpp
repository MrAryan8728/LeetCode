class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1,cnt2;
        int elem1,elem2;
        cnt1 = cnt2 = 0;
        elem1 = elem2 = INT_MIN;
        
        for(int i = 0;i < n;i++){
            if(cnt1 == 0 and elem2 != nums[i]){
                cnt1 = 1;
                elem1= nums[i];
            }else if(cnt2 == 0 and elem1 != nums[i]){
                cnt2 = 1;
                elem2 = nums[i];
            }
            else if(nums[i] == elem1) cnt1++;
            else if(nums[i] == elem2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int> ls;
        cnt1 = 0,cnt2 = 0;
        for(int i = 0;i < n;i++){
            if(nums[i] == elem1) cnt1++;
            if(nums[i] == elem2) cnt2++;
        }
        
        int mn = int(n/3) + 1;
        if(cnt1 >= mn) ls.push_back(elem1);
        if(cnt2 >= mn) ls.push_back(elem2);
        
        return ls;
    }
};