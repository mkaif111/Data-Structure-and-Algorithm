#include<iostream>
using namespace std;

bool isValid(int n, int r,int c,int ax ,int ay){
   
    if(r>=n || c>=n || c<0 || r<0 || r==ax || c==ay)
        return false;
    int x_diagonal[] = {-1,-1,1,1};
    int y_diagonal[] = {-1,1,1,-1};
    

    for(int i=0;i<4;i++){
        int row = ax + x_diagonal[i];
        int col = ay + y_diagonal[i];

        while((row>=0 && col>=0) && (row<n && col <n))
        {
            if(r==row && c==col)
                return false;
            row = row + x_diagonal[i];
            col = col + y_diagonal[i];
        }


    }
    

    return true;
    
}

bool dfs(int n,int bx,int by,int cx,int cy ,int ax,int ay,bool** visited){
    if(bx==cx and by==cy)
        return true;

    visited[bx][by] = true;

    int x_step[] = {-1,0,1,0,-1,-1,1,1};
    int y_step[] = {0,1,0,-1,-1,1,1,-1};

    for(int i=0;i<8;i++){
        int r = bx + x_step[i];
        int c = by + y_step[i];

        if(!visited[r][c])
        {  
            if(isValid(n,r,c,ax,ay))
            {
                if(dfs(n,r,c,cx,cy,ax,ay,visited))
                {return true;}
           }
        }
    }

    visited[bx][by]= false;
  
    return false;
}

int main(){
    int n;
    cin>>n;

    int ax,ay;
    cin>>ax>>ay;

    int bx,by;
    cin>>bx>>by;

    int cx,cy;
    cin>>cx>>cy;

    bool** visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[n]();
        
    }

    if(dfs(n,bx-1,by-1,cx-1,cy-1,ax-1,ay-1,visited))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;


}