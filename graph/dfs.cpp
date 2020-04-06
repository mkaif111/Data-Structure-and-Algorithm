#include<bits/stdc++.h>
using namespace std;

void dfs(int** edges , int sv , int n,bool* visited){
    if(visited[sv]==false)
        cout<<sv+1<<" ";
    visited[sv] = true;

    for(int i=0;i<n;i++){
        if(sv==i)
            continue;

        if(edges[sv][i]==1 && visited[i]==false)
             dfs(edges,i,n,visited);
    
        
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
    }
    for(int i=0;i<n;i++)
        dfs(edges,i,n,visited);

    for(int i=0;i<n;i++)
        delete edges[i];

    delete edges;
    delete visited;
    




}