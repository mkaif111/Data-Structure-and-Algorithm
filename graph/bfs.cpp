#include<bits/stdc++.h>
using namespace std;

void bfs(int** edges , int sv, int n, bool* visited){
    queue<int>q;

    q.push(sv);

    while(!q.empty()){
        int curr_v = q.front();
        cout<<curr_v+1<<" ";
        q.pop();
        visited[curr_v] = true;

        for(int i=0;i<n;i++){
            if(curr_v==i)
                continue;
            if(edges[curr_v][i]==1 && visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
        

    }


}

int main(){

    int n,e;
    cin >> n >> e;

    int** edges = new int*[n];
    for(int i=0;i<n;i++){

        edges[i] = new int[n];

        for(int j=0;j<n;j++)
            edges[i][j]=0;

    }

    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
        visited[i] = false;

    while(e--)
    {
        int row,col;
        cin >> row >> col;
        edges[row][col] = 1;
        edges[col][row] = 1;
    }
    for(int i=0;i<n;i++)
     {  if(visited[i]==false)
     
         bfs(edges,i,n,visited);

    }
           
            

    for(int i=0;i<n;i++)
        delete edges[i];

    delete edges;
    delete visited;
    




}