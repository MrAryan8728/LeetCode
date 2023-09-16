class Solution {
public:
/*
Dijkstra's Algorithm
Steps
    Create a 2D effort array and define directional changes using dx and dy.
    Initialize cell efforts to maximum value.
    Call dijkstra to find the minimum effort.
    Initialize a priority queue to store (-effort, {x, y}) to make it return the minimum element.
    Push the top-left cell into the queue with initial effort as 0.
    While the priority queue is not empty:
    Pop the cell with the least effort.
    If cost is greater than existing effort, skip.
    If at bottom-right cell, return minimum effort.
    Explore four directions, update efforts, and push to queue if lower effort found.
    Return the minimum effort from top-left to bottom-right cell.
Complexity
    Time complexity:O(M∗N∗log(M∗N))O(M * N * log(M * N))O(M∗N∗log(M∗N))
    The time complexity for Dijkstra's Algorithm is O(E * log(E)), where E is the number of edges in the graph. In our case, we can consider the number of edges are M * N.
    Space complexity:O(M∗N)O(M * N)O(M∗N)
    Since we are storing the minimum effort for the path from the starting point to each cell, then the space complexity is O(M * N).
*/
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();

        int delx[4] = {-1,0,1,0};
        int dely[4] = {0,1,0,-1};

        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int ex = it.second.first;
            int ey = it.second.second;

            if(ex == n - 1 and ey == m - 1) return diff;

            for(int i = 0;i < 4;i++){
                int nx = ex + delx[i];
                int ny = ey + dely[i];
                if(nx >= 0 and nx < n and ny >= 0 and ny < m){
                    int nEffort = max(abs(heights[ex][ey] - heights[nx][ny]),diff);
                    if(nEffort < dist[nx][ny]){
                        dist[nx][ny] = nEffort;
                        pq.push({nEffort,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};