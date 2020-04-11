#include<bits/stdc++.h>
using namespace std;
#define MAXN 102

bool isValid(char graph[][MAXN],int x ,int y,int n,int m,bool** visited,string s){
    if (x>=n || y>=m || (graph[x][y]!=s[0]) || x<0 || y<0 || visited[x][y])
        return false;
    
    return true;
}
bool dfs(char graph[][MAXN] , int n , int m , int row , int col ,string s, bool** visited){
    if(s.length()==1)
        return true;
    
    // cout<<row << col <<" row col"<<endl;
    int x_step[] = {-1,-1,0,1,1,1,0,-1};
    int y_step[] = {0,1,1,1,0,-1,-1,-1};
    
    visited[row][col] = true;
    s = s.substr(1);
    
    for(int i=0;i<8;i++)
    {
        int x = row + x_step[i];
        int y = col + y_step[i];
        // cout<<x<<y<<" ";
        if(isValid(graph,x,y,n,m,visited,s))
           { 
            
            
            // cout<<graph[x][y]<<" substr : "<<s[0]<<" "<< s <<" "<<x<<y<< endl;
               
            bool ans = dfs(graph,n,m,x,y,s,visited);
            if(ans)
                {return ans;}
            
             visited[row][col] = false;
            
            }
       
        
        
        
    }
    
    return false;
    
    
}
int solve(char Graph[][MAXN],int N, int M)
{
	// Write your code here.
    bool **visited = new bool*[N];
    for(int i=0;i<N;i++){
        visited[i] = new bool[M];
        for(int j=0;j<M;j++){
            visited[i][j] = false;
        }
    }
    
    string s = "CODINGNINJA";
    int row = 0;
    int col = 0;
    bool ans;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            char c = Graph[i][j];
            if(c=='C'){
                // cout<<i;
                ans = dfs(Graph , N , M , i , j ,s , visited);
                if(ans)
                    return 1;
                
            }
            
        }
    }
   
    
    return 0;
    
    
}


int main()
{
	int N,M,i;
	char Graph[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>Graph[i];
	}
	cout<<solve(Graph,N,M)<<endl;
}