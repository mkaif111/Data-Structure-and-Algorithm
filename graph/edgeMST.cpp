#include<bits/stdc++.h>
using namespace std;

#define mx 500
#define NIL -1
vector<int> adj[mx];
struct edges{
    int u,v,w;
};

int min(int x,int y){
    return (x<y)?x:y;
}
int low[mx],disc[mx];


bool comp(edges u , edges v){
    return u.w<=v.w;
}

int find(int v , int* parent){
    if(v==parent[v])
        return v;
    parent[v] = find(parent[v] , parent);
    
    return parent[v];
}

void union_algo(int x , int y,int* parent,int*rank){
    int x_rep = find(x,parent), y_rep=find(y,parent);
    
    if(x_rep == y_rep) return ;
    
    if(rank[x_rep]<rank[y_rep]) parent[x_rep] = y_rep;
    else if(rank[y_rep]<rank[x_rep]) parent[y_rep] = x_rep;
    else parent[y_rep]= x_rep,rank[x_rep]++;
}

void dfs(int u , bool* visited ,int* parent){


    // A static variable is used for simplicity, 
    // we can avoid the use of static
    // variable by passing a pointer
    static int time = 0;


    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices aadjacent to this
    
    for (auto v: adj[u])
    {
      
        if (!visited[v])
        {
            
            parent[v] = u;
            dfs(v, visited,parent);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);

        }

        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }


}

void Ap(int n){

    
    int* parent = new int[n];
    bool* visited = new bool[n];

    for(int i=0;i<n;i++){
        parent[i] = NIL;
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i,visited,parent);
    }

   
    delete parent;
    return ;
}


int main()
{
	//code
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<mx;i++) adj[i].clear();
    edges *edge = new edges[m];
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[i].u = u;
        edge[i].v = v;
        edge[i].w = w;
    }
    edges *temp = new edges[m];
    for(int i=0;i<m;i++) temp[i] = edge[i];
    sort(edge,edge+m,comp);
    Ap(n);
    
    string res[n][n];
    int* parent_un = new int[n];
    int* rank = new int[n];
    for(int i=0;i<n;i++) parent_un[i]=i,rank[i] = 0;
    
    for(int i=0;i<m;i++){
        int u = edge[i].u;
        int v = edge[i].v;
        int x = find(u,parent_un);
        int y = find(v,parent_un);

        if(low[v]>disc[u]){
            res[u][v]="any";
        }
        else if(x!=y){
            res[u][v] = "at least one";
            union_algo(x,y,parent_un,rank);
        }
        
        else if(x==y){
            res[u][v] = "none";
        }
    }
    
    for(int i=0;i<m;i++){
        cout<<res[temp[i].u][temp[i].v]<<endl;
    }    
    
    
	return 0;
}
