class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int island = 0;

        vector<vector<int>> vis(m,vector<int>(n,0));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1' and !vis[i][j]){
                    island++;
                    traversal(i,j,grid,vis);
                }
            }
        }
        return island;
    }
    void traversal(int i,int j,vector<vector<char>> &grid,vector<vector<int>>& vis){
        vis[i][j] = 1;

        int m = grid.size();
        int n = grid[0].size();
        
        int delx[4] = {-1,0,1,0};
        int dely[4] = {0,1,0,-1};

        for(int k = 0;k < 4;k++){
            int nr = i + delx[k];
            int nc = j + dely[k];
            if(nr >= 0 and nr < m and nc >= 0 and nc < n and !vis[nr][nc] and grid[nr][nc] == '1'){
                traversal(nr,nc,grid,vis);
            }
        }
    }
};