class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> r,c;
        // just row and column having zero.
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == 0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        // just row and column ko set krdo.
        for(int i = 0;i < r.size();i++){
            for(int j = 0;j < n;j++){
                matrix[r[i]][j] = 0;
            }
        }
        // just row and column ko set krdo.
        for(int i = 0;i < m;i++){
            for(int j = 0;j < c.size();j++){
                matrix[i][c[j]] = 0;
            }
        }
    }
};