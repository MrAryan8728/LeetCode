class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(),strs.end());
        string st = strs[0],end = strs[n-1],ans = "";
        for(int i = 0;i < st.size();i++){
            if(st[i] == end[i]){
                ans += st[i];
            }else 
                break;
        }
        return (ans.size() > 0)?ans:"";
    }
};