#include<bits/stdc++.h>
using namespace std;



//BFS level order problem
//if weight is given in this problem then it would be solved by dijkstra algorithm



#define mx 100000
vector<int> edges[mx];
bool visited[mx+1];
int dis[mx+1];

void bfs(int src){
    visited[src] = true;
    queue<int> q;
    dis[src]=0;
    
    q.push(src);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(auto x:edges[curr]){
            if(!visited[x]){
                visited[x]=true;
                dis[x] = dis[curr] + 1;
                q.push(x);
            }
        }
    }
    
    return ;
    
}

int main(){
    
    int t,n,m;
    cin>>t;
    while(t--){
        
        
        cin>>n>>m;
        for(int i=0;i<n;i++){
            edges[i].clear();
        }
        
        memset(visited,false,sizeof(visited));
        
        
        for(int i=0;i<m;i++){
            int x, y;
            cin>>x>>y;
            edges[x-1].push_back(y-1);
            edges[y-1].push_back(x-1);
        }
        
        
        bfs(0);
        
        cout<<dis[n-1]<<endl;
        
        
   
        
        
    }
}