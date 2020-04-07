#include <iostream>
using namespace std;

void dfs(int** edges,int sv ,int n, bool* visited){
    
    visited[sv] = true;
    
    for(int i=0;i<n;i++){
        if (!visited[i] && edges[sv][i]==1 && i!=sv)
            dfs(edges,i,n,visited);
    }
    
    
}

int main() {
    int V, E;
    cin >> V >> E;
    
	int** edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i] = new int[V];
        for(int j=0;j<V;j++)
            edges[i][j] = 0;
    }
    
    for(int i=0;i<E;i++){
        int x , y;
        cin >> x >> y;
        edges[x][y]=1;
        edges[y][x]=1;
    }
    
    bool* visited = new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    dfs(edges,0,V,visited);
    
    string ans="true";
    for(int i=0;i<V;i++){
        if(!visited[i])
            ans="false";
    }
    
    cout<<ans;
  

  return 0;
}
