// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class node{
    public:
    int t,x,y;
};
class Solution 
{
    public:
    bool isValid(int r,int c, int n , int m){
        if(r>=n or r<0 or c<0 or c>=m)
            return 0;
        return 1;
    }
        
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<node> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    node temp;
                    temp.t = 0;
                    temp.x = i;
                    temp.y = j;
                    q.push(temp);
                }
            }
        }
        
        node ans;
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            ans = q.front();
            q.pop();
            int r = ans.x;
            int c = ans.y;
            int t = ans.t;
            if(isValid(r+1,c,n,m) and grid[r+1][c]==1){
                grid[r+1][c] = 2;
                node temp;
                temp.t = t+1;
                temp.x = r+1;
                temp.y = c;
                q.push(temp);
            }
            if(isValid(r-1,c,n,m) and grid[r-1][c]==1)
            {
                grid[r-1][c] = 2;
                node temp;
                temp.x = r-1;
                temp.y = c;
                temp.t = t+1;
                q.push(temp);
            }
            if(isValid(r,c+1,n,m) and grid[r][c+1] == 1){
                grid[r][c+1] = 2;
                node temp;
                temp.x = r;
                temp.y = c+1;
                temp.t = t+1;
                q.push(temp);
            }
            if(isValid(r,c-1,n,m) and grid[r][c-1] == 1){
                grid[r][c-1] = 2;
                node temp;
                temp.t = t+1;
                temp.x = r;
                temp.y = c-1;
                q.push(temp);
            }
            
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ans.t;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends