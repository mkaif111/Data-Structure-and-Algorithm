// https://leetcode.com/problems/minimum-falling-path-sum/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        vector<vector<int>> ans(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++){
            ans[n-1][i] = matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<n;j++){
                if(j==0){
                    ans[i][j] = matrix[i][j] + min(ans[i+1][j],ans[i+1][j+1]);
                }
                else if(j==n-1){
                    ans[i][j] = matrix[i][j] + min(ans[i+1][j-1],ans[i+1][j]);
                }
                else
                ans[i][j] = matrix[i][j] + min(min(ans[i+1][j-1],ans[i+1][j]),ans[i+1][j+1]);
            }
        }
        
        // for(int i=n-2;i>=0;i--){
        //     ans[i][0] = matrix[i][0] + min(ans[i+1][0],ans[i+1][1]);
        //     ans[i][n-1] = matrix[i][n-1] + min(ans[i+1][n-1],ans[i+1][n-2]);
        // }
        
        int minFallPath = INT_MAX;
        for(int i=0;i<n;i++){
            minFallPath = min(minFallPath,ans[0][i]);
        }
        
       
        
        return minFallPath;
        
    }
};