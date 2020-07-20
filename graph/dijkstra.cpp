#include <bits/stdc++.h>
using namespace std;

 int source = 0;

int getMinV(bool* visited ,int* dist , int n){
    	
    int minWV = -1;
    
    for(int i=0;i<n;i++){
        
        if(!visited[i] && ( (minWV==-1) || dist[minWV]>dist[i] ) )
            minWV = i;
    }
    
    return minWV; // return index whose have min. weight
}
void dijkstra(int** edges , int n){
    
    bool* visited = new bool[n](); // false initially
    int* dist = new int[n];
    
    
  
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
        
    }
    
   
    dist[source] = 0;
    
    // transverse through all n-1 edges
    for(int i=0;i<n-1;i++){
        
        int minVertex = getMinV(visited,dist,n);
        
        visited[minVertex] = true;
        
        for(int j=0;j<n;j++){
            
            if(edges[minVertex][j]!=0 && !visited[j]){
                if(dist[j]>edges[minVertex][j]+dist[minVertex]){
                    dist[j] = edges[minVertex][j]+dist[minVertex];
                    
                }
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<dist[i]<<endl;
    }
    
    return ;
    
    
}


int main()
{
  	int n,e;
  	cin>>n>>e;
    
    
    int**edges = new int*[n];
    for(int i=0;i<n;i++){
        edges[i] = new int[n];
        for(int j=0;j<n;j++){
            edges[i][j] = 0;
        }
    }
    
    for(int i=0;i<e;i++){
        int x , y, w;
        cin >> x >> y >> w;
        edges[x][y] = w;
        edges[y][x] = w;
    }
    
    dijkstra(edges,n);
    


  return 0;
}
