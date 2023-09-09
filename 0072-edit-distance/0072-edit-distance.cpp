/*
Recursive + Memoized Approach:


function minOperations(word1, word2, i, j, memo):
    // Base case: if either string is empty, return the length of the other string
    if i == 0:
        return j
    if j == 0:
        return i
    
    // Check if the result is already memoized
    if memo[i][j] != null:
        return memo[i][j]
    
    // If the characters at the current positions are equal, no operation is needed
    if word1[i-1] == word2[j-1]:
        memo[i][j] = minOperations(word1, word2, i-1, j-1, memo)
    else:
        // Perform the three possible operations and choose the minimum
        insert = 1 + minOperations(word1, word2, i, j-1, memo)
        delete = 1 + minOperations(word1, word2, i-1, j, memo)
        replace = 1 + minOperations(word1, word2, i-1, j-1, memo)
        memo[i][j] = min(insert, delete, replace)
    
    return memo[i][j]

function minDistance(word1, word2):
    memo = create a 2D array of size (word1.length + 1) x (word2.length + 1) and initialize with null
    return minOperations(word1, word2, word1.length, word2.length, memo)

Tabulated + Space Optimized Approach:


function minDistance(word1, word2):
    m = word1.length
    n = word2.length
    
    // Create a 2D array to store the minimum number of operations
    dp = create a 2D array of size 2 x (n + 1)
    
    // Initialize the base cases
    for i from 0 to n:
        dp[0][i] = i
    for i from 0 to 1:
        dp[i][0] = i
    
    // Fill up the dp array
    for i from 1 to m:
        for j from 1 to n:
            if word1[i-1] == word2[j-1]:
                dp[i % 2][j] = dp[(i-1) % 2][j-1]
            else:
                insert = 1 + dp[i % 2][j-1]
                delete = 1 + dp[(i-1) % 2][j]
                replace = 1 + dp[(i-1) % 2][j-1]
                dp[i % 2][j] = min(insert, delete, replace)
    
    return dp[m % 2][n]

Note: In the tabulated + space optimized approach, we use a 2D array of size 2 x (n + 1) instead of (m + 1) x (n + 1) to save space. We use the modulo operator to access the correct row in the dp array.
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(),n =  word2.size();
        vector<vector<int>> dp(501,vector<int>(501,0));
        // return solve(word1,word2,m-1,n-1,dp);
        for(int i = 0;i <= m;i++) dp[i][0] = i;
        for(int j = 0;j <= n;j++) dp[0][j] = j;

        for(int i = 1;i <= m;i++){
            for(int j = 1;j <= n;j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else
                dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
        }

        return dp[m][n];
    }
    int solve(string word1,string word2,int i,int j,vector<vector<int>> &dp){
        if(i < 0) return j + 1;
        if(j < 0) return i + 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = 0 + solve(word1,word2,i-1,j-1,dp);
        
        return dp[i][j] = min(1 + solve(word1,word2,i-1,j,dp),min(1 + solve(word1,word2,i,j-1,dp),1 + solve(word1,word2,i-1,j-1,dp)));
    }
};