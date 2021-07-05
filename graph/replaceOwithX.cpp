// { Driver Code Starts
// Initial Template for C++
// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>> &mat,int r, int c){
        if(r<0 or r>=mat.size() or c<0 or c>=mat[0].size() or  mat[r][c]!='-')
            return;
        mat[r][c] = 'O';
        dfs(mat,r-1,c);
        dfs(mat,r,c+1);
        dfs(mat,r+1,c);
        dfs(mat,r,c-1);
        return ;
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
      
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(mat[i][j] == 'O')
                    mat[i][j] = '-';
            }
        }
     
        //left and right edge
        for(int i=0;i<n;i++){
            if(mat[i][0] == '-')
                dfs(mat,i,0);
            if(mat[i][m-1] == '-')
                dfs(mat,i,m-1);
        }
       //bottom and top edge
        for(int i=0;i<m;i++){
            if(mat[0][i] == '-')
                dfs(mat,0,i);
            if(mat[n-1][i] == '-')
                dfs(mat,n-1,i);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(mat[i][j] == '-')
                    mat[i][j] = 'X';
            }
        }
       
        return mat;
    }
};
// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends