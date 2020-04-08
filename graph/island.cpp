#include<queue>
bool bfs(int** edges , int sv , int n , bool* visited){
    int count=0;
    
    queue<int> q;
    q.push(sv);
    
    visited[sv] = true;
    while(!q.empty()){
        
        int curr_v = q.front();
        count++;
        q.pop();
        visited[curr_v] = true;
        
        
    for(int i=0;i<n;i++){
        if(i==curr_v)
            continue;
        if(edges[curr_v][i] && !visited[i])
        {
            q.push(i);
            
        }
        
    }
        
        }
    
    return (count>0)?true:false;
    
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	// Write your code here .
    int** edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
            edges[i][j]=0;
    }
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i]=false;
    
    for(int i=0;i<m;i++)
    {	int x=u[i]-1,y=v[i]-1;
     	
        edges[x][y] = 1;
     	edges[y][x] = 1;
    }
   
    int count = 0;
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(bfs(edges,i,n,visited))
                count++;
        }
        
    }
    
    return count;
    
    
}