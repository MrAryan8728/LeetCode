class Solution {
public:
    /*
In order to merge overlapped intervals, we should be able to tell whether two intervals are overlapped.

Given two intervals [a, b] and [c, d], they do not overlap with each other if b < c or d < a.

So they overlap if a <= d and c <= b as below examples:

1)
-----
a   b

  -----
  c   d
2)
	-----
	a   b

  -----
  c   d
If we sort intervals by starts of both intervals, then a <= c, since c < d, so a < d -- one requirement of overlapped intervals is met.

Thus, after we sort intervals by starts, two intervals overlap if c <= b.

All in all, we sort the intervals given in the problem by starts, and then iterate through the sorted intervals - we merge overlapped intervals on the fly.

Is that one-pass enough to merge over-lapped intervals? Yes, since intervals[i + 1] cannot overlap with intervals[i - 1] if intervals[i] doesn't in the sorted sequence.
    */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() == 0)
        return intervals;
        sort(intervals.begin(),intervals.end());
        vector<int> temp = intervals[0];
        for(int i = 1;i < intervals.size();i++){
            if(temp[1] >= intervals[i][0]){
                temp[1] = max(temp[1],intervals[i][1]);
            }else{
                ans.push_back(temp);
                temp = intervals[i];
            }
        }
        ans.push_back(temp);
        return ans;
    }

};