#include<bits/stdc++.h>
using namespace std;

#define N 9

bool isSafeinBox(int grid[N][N],int row , int col , int num){
  int row_factor = row - row%3;
  int col_factor = col - col%3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(grid[row_factor+i][col_factor+j]==num){return false;}
    }
  }

  return true;

}

bool isSafeinRow(int grid[N][N],int row , int num){
        for(int i=0;i<N;i++){
          if(grid[row][i]==num){
            return false;
          }
        }

      return true;
}

bool isSafeinColumn(int grid[N][N],int col,int num){
        for(int i=0;i<N;i++){
          if(grid[i][col]==num){
            return false;
          }
        }
        return true;
}




bool isSafe(int grid[N][N],int row,int col , int num){

      if(isSafeinBox(grid,row,col,num) && isSafeinColumn(grid,col,num) && isSafeinRow(grid,row,num)){
        return true;
      }
      return false;
}

bool findEmptyLocation(int grid[N][N],int &row,int &col){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(grid[i][j]==0){
        col = j;
        row = i;
        return true;
      }
    }
  }
  return false;
}

bool sudokuSolver(int grid[][9]){
  int row,col;
  if(!findEmptyLocation(grid,row,col)){
    return true;
  }
 for(int i=1;i<=9;i++){
   if(isSafe(grid,row,col,i)){
     grid[row][col] = i;
     if(solveSudoku(grid)){
       return true;
     }
     grid[row][col]=0;
   }
 }
  return false;
}


int main(){
  int grid[N][N];
  for(int i=0;i<N;i++){
    string s;
    cin>>s;
    for(int j=0;j<N;j++){
      grid[i][j] = s[i]-'0';
    }
  }
  solveSoduku(grid);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<grid[i][j];
    }
    cout<<endl;
  }


}
