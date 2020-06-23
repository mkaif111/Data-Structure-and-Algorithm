#include <iostream>
using namespace std;
char grid[50][50];
bool visited[50][50];

void dfs(int n,int m,int r, int c){
    visited[r][c] =true;
    
    int x_step[4] = {-1,0,1,0};
    int y_step[4] = {0,1,0,-1};
    
    for(int i=0;i<4;i++){
        int rr = r+x_step[i];
        int cc = c+y_step[i];
        
        if(rr>=0 and cc>=0 and rr<n and cc<m){
            if(!visited[rr][cc] && grid[rr][cc]=='X')
                dfs(n,m,rr,cc);
        }
    }
    
    return ;
}

int main() {
	//code
	int t;
    cin>>t;
	while(t--){
	    int n,m;
	    cin>>n>>m;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            cin>>grid[i][j];
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            visited[i][j]=false;
	        }
	    }
	    int count=0;
	    // cout<<count<<endl;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]=='X' and !visited[i][j])
	               { 
	                   dfs(n,m,i,j);
	                   count++;
	                   
	               }
	        }
	    }
	    
	    cout<<count<<endl;
	}
	return 0;
}