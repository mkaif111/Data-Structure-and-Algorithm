#include<bits/stdc++.h>
int sol[20][20];
bool isPossible(int n,int row,int col,int maze[][20]){
    if((row>n-1 || col>n-1) || (row<0 || col<0) || (sol[row][col]==1) || maze[row][col]==0){
        return false;
    }
    return true;
}



void rat_fun(int maze[][20],int n,int row,int col){
    if(row==n-1 && col==n-1){
        sol[row][col]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    if(isPossible(n,row,col,maze)){
        sol[row][col]=1;
        rat_fun(maze,n,row-1,col);
        // rat_fun(maze,n,row,col-1);
        rat_fun(maze,n,row+1,col);
        rat_fun(maze,n,row,col-1);
        rat_fun(maze,n,row,col+1);
        sol[row][col]=0;
    }


    return ;

}


void solution(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */



    memset(sol,0,20*20*sizeof(int));

    rat_fun(maze,n,0,0);



}
