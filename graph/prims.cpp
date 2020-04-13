#include <bits/stdc++.h>
using namespace std;

int getMinV(bool* visited ,int* weight , int n){
    	
    int minWV = -1;
    
    for(int i=0;i<n;i++){
        
        if(!visited[i] && ( (minWV==-1) || weight[minWV]>weight[i]))
            minWV = i;
    }
    
    return minWV;
}
void prims(int** edges , int n){
    
    bool* visited = new bool[n](); // false initially
    int* weight = new int[n];
    int* parent = new int[n];
    
  
    for(int i=0;i<n;i++){
        weight[i] = INT_MAX;
        
    }
    
    parent[0] = -1;
    weight[0] = 0;
    
    
    for(int i=0;i<n-1;i++){
        
        int minWVertex = getMinV(visited,weight,n);
        
        visited[minWVertex] = true;
        
        for(int j=0;j<n;j++){
            
            if(edges[minWVertex][j]!=0 && !visited[j]){
                if(weight[j]>edges[minWVertex][j]){
                    weight[j] = edges[minWVertex][j];
                    parent[j] = minWVertex;
                }
            }
        }
    }
    
    for(int i=1;i<n;i++){
        cout<<min(i,parent[i])<<" "<<max(parent[i],i)<<" "<<weight[i]<<endl;
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
    
    prims(edges,n);
    


  return 0;
}
