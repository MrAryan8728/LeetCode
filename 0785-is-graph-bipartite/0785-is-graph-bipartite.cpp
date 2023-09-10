class Solution {
public:
    /*
The approach used in this solution is to perform a depth-first search (DFS) on the graph and assign colors to the nodes in a way that ensures no two adjacent nodes have the same color. If it is possible to assign colors to all nodes without any conflicts, then the graph is bipartite.


The main function isBipartite initializes a vector color to keep track of the color assigned to each node. It starts by assigning all nodes a color of -1, indicating that they have not been assigned a color yet. Then, it iterates through each node in the graph and checks if it has been assigned a color. If not, it calls the dfs function to perform a DFS starting from that node.


The dfs function takes in the current node, the current color, the graph, and the color vector as input. It assigns the current color to the current node and then iterates through its neighbors. If a neighbor has not been assigned a color, it recursively calls dfs on that neighbor with the opposite color. This ensures that adjacent nodes have different colors. If a neighbor has been assigned the same color as the current node, it means there is a conflict and the graph is not bipartite. In this case, the function returns false.


If the dfs function completes without finding any conflicts, it means all nodes have been assigned colors in a way that satisfies the bipartite condition. Therefore, the isBipartite function returns true.


Overall, this solution uses DFS to assign colors to the nodes of the graph and checks for conflicts along the way to determine if the graph is bipartite.
    */
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int clr = 0;
        
        vector<int> color(n,-1);
        for(int i = 0;i < n;i++){
            if(color[i] == -1){
                if(!dfs(i,clr,graph,color)) return false;
            }
        }
        
        return true;
    }
    bool dfs(int i,int clr,vector<vector<int>>& graph,vector<int> &color){
        color[i] = clr;
        
        for(auto it: graph[i]){
            if(color[it] == -1){
                if(!dfs(it,!clr,graph,color)) return false;
            }else if(color[it] == clr){
                return false;
            }
        }
        
        return true;
    }
};