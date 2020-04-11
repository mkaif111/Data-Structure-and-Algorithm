#include<iostream>
#include<vector>
using namespace std;
#define NMAX 55

char cake[NMAX][NMAX];


bool isValid(char graph[NMAX][NMAX] , int x , int y , int n , bool** visited ){
    if (x>=n || y>=n || (graph[x][y]!='1') || x<0 || y<0 || visited[x][y])
        return false;
    
    return true;
}

int bfs(char cake[][NMAX], int row , int col ,int n , bool** visited ){
    
    int count=0;
    int x_step[] = {-1,-1,0,1,1,1,0,-1};
    int y_step[] = {0,1,1,1,0,-1,-1,-1};
    
    
    
}


int dfs(char cake[NMAX][NMAX] , int row , int col , int n, bool** visited){

    if(visited[row][col])
        return 0;
    
    int x_step[] = {-1,0,1,0};
    int y_step[] = {0,1,0,-1};
    
    visited[row][col] = true;
    int count=0;
    
     for(int i=0;i<4;i++)
    {
        int x = row + x_step[i];
        int y = col + y_step[i];
        // cout<<x<<y<<" ";
        if(isValid(cake,x,y,n,visited))
           { 
            
            
            // cout<<cake[x][y]<<" "<<" "<<" "<<x<<y<< endl;
           
            visited[x][y]=true;
            count += dfs(cake,x,y,n,visited);
            
             
        
            
            
             
            
            }
     
       
        
        
        
    }
    
   
    
    return count+1;
    
   
}


int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
    // int count = 0;
    int ans = -1;
	bool **visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[n];
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j]=='1'){
                int count = dfs(cake,i,j,n,visited);
                if(count>ans)
                    ans = count;
            }
        }
    }
    
    
    return ans;
    
    
}


int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
}