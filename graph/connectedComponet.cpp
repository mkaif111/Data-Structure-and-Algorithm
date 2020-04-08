#include<bits/stdc++.h>
using namespace std;


vector<int> bfs(int **edges,int start,int n,bool *visited){
    vector<int> v;
    queue<int> q;
    
    q.push(start);
    v.push_back(start);
    visited[start]=true;
    
    while(!q.empty()){
        int curr_v = q.front();
        q.pop();
        if(!visited[curr_v])
        	v.push_back(curr_v);
        visited[curr_v]=true;
        for(int i=0;i<n;i++){
            if(edges[curr_v][i] && !visited[i] && i!=curr_v)
            {
                q.push(i);
                
            }
        }
    }
    return v;
}



int main()
{
  int V, E, tempX, tempY;
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
    
   
    for(int i=0;i<V;i++){
        if(!visited[i])
    {
    vector<int> v=bfs(edges,i,V,visited);
            
    if(v.empty()==false)
    {	sort(v.begin(),v.end());
          for(auto x:v)
              cout<<x<<" ";
        cout<<endl;
        

    }
        
        }
        
        
    }
        
    
  
  return 0;
}
