#include<bits/stdc++.h>
using namespace std;
#define MX 100005

// Topic : Topological sorting and strongly connected graph( 'KosaRaju' )

vector<int> edges[MX+1];
bool visited[MX+1];
stack<int> s;

void dfs1(int u){
    
    visited[u] = true;
    
    for(auto x:edges[u]){
        if(!visited[x])
            dfs1(x);
    }
    
    s.push(u);
    
}

void dfs2(int u){
    
    visited[u] = true;
    
    for(auto x:edges[u]){
        if(!visited[x])
            dfs2(x);
    }
}


int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        
        
        
        for(int i=0;i<MX;i++){
            edges[i].clear();
        }
        
        memset(visited , false , sizeof(visited));
        while(!s.empty())
            s.pop();
        
        int n,m;
        cin>>n>>m;
        
        for(int i=0;i<m;i++){
            int x , y;
            cin>>x>>y;
            edges[x-1].push_back(y-1);
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i])
                dfs1(i);
        }
        
        int count=0;
        
        // reinitialize visited array to transverse through topological order of graph
        memset(visited , false , sizeof(visited));
        
        while(!s.empty()){
            
            int element = s.top();
            s.pop();

            if(!visited[element])
            {
                dfs2(element);
                count++;
            }
            
            
            
        }
        
        
        cout<<count<<endl;
        
    }
    
}