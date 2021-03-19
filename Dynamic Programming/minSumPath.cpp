// https://leetcode.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        dp[n-1][m-1] = grid[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            dp[i][m-1] = grid[i][m-1] + dp[i+1][m-1];
        }
        for(int i=m-1;i>=0;i--){
            dp[n-1][i] = grid[n-1][i] + dp[n-1][i+1];
        }
        for(int i = n-2;i>=0;i--){
            for(int j = m-2;j>=0;j--){
                dp[i][j] = min(dp[i+1][j],dp[i][j+1]) + grid[i][j];
            }
        }
        
        return dp[0][0];
        
    }
};