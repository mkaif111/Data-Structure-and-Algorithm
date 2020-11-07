#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>> &board,int n,int r,int c){
    if(r>=n or c>=n or c<0 or r<0){
        return;
    }
    if(board[r][c] !=1){
        return;
    }
    board[r][c] = 2;
    solve(board,n,r-2,c-1);
    solve(board,n,r-2,c+1);
    solve(board,n,r-1,c-2);
    solve(board,n,r-1,c+2);
    solve(board,n,r+1,c-2);
    solve(board,n,r+1,c+2);
    solve(board,n,r+2,c-1);
    solve(board,n,r+2,c+1);
    return ;
    
}
int main(){
    int n; cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int el; cin>>el;
            board[i][j] = el;
        }
    }
    solve(board,n,0,0);
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1)
                count++;
        }
    }
    cout<<count<<endl;


    return 0;
}