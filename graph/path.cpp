
#include<bits/stdc++.h>
using namespace std;

bool dfs(int** edges , int n , int row , int col,bool** visited){
    if(edges[row][col]==2)
        return true;
    int x_step[] = {-1,0,1,0};
    int y_step[] = {0,1,0,-1};
    visited[row][col] = true;
    
    for(int i=0;i<4;i++){
        int r = row + x_step[i];
        int c = col + y_step[i];
        
        if(r<n && c<n && r>=0 && c>=0 && !visited[r][c]){
            if(edges[r][c]==2)
                return true;
            if(edges[r][c]==3)
                if(dfs(edges , n , r , c,visited))
                    return true;
        }
    }
    
    return false;
}

int main() {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int n;
	    cin>>n;
	    int **edges = new int*[n];
	    
	    for(int i=0;i<n;i++){
	        edges[i] = new int[n];
	        for(int j=0;j<n;j++){
	            cin>>edges[i][j];
	        }
	    }

        bool** visited = new bool*[n];
        for(int i=0 ; i<n;i++){
            visited[i] = new bool[n]();
        }
    
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(edges[i][j]==1){
	                if(dfs(edges,n,i,j,visited))
	                    {ans = 1;
	                    break;}
	            }
	        }
	    }
	    printf("%d \n",ans);
	}
	return 0;
}