#include<bits/stdc++.h>
using namespace std;
#define MAXN 51


bool dfs(char board[][MAXN] ,int row,int col,int n,int m ){
   queue<pair<int,int>> q;
    q.push(make_pair(row,col));
    int p_row = row;
    int p_col = col;
    char color = board[row][col];
    bool **visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
        for(int j=0;j<m;j++)
            visited[i][j] = false;
    }
    
    int x_step[] = {1,0,-1,0};
    int y_step[] = {0,1,0,-1};
    // visited[row][col] = true;
    int count=0;
    while(!q.empty()){

        pair<int,int> p = q.front();
        q.pop();

        if((p.first==p_row && p.second == p_col) && count>=4)
            return true;
        for(int i=0;i<4;i++){
            int r = p.first + x_step[i];
            int c = p.second + y_step[i];

            if( r<n && c<m && r>=0 & c>=0)
            {
                if( board[r][c]==color)
                { if(!visited[r][c]){
                        q.push(make_pair(r,c));
                        visited[r][c]=true;
                        count++;
                    }
                    else
                    {
                        if((r==p_row && c==p_col) && count>=4) return true;
                    }
                }
            }
        } //end for loop

        

    } // end while loop

    return false;
        
}

int solve(char board[][MAXN],int n, int m)
{
	// Write your code here.
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            bool ans = dfs(board,i,j,n,m);
            if (ans) return 1;
        }
    }

    return 0;
    
}



int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}







int main(){

}