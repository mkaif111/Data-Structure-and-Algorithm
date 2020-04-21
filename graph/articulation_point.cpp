#include<bits/stdc++.h>
using namespace std;

#define MAX 100000
#define NIL -1
vector<int> edges[MAX+1];
bool visited[MAX+1];

void dfs(int u , bool* visited , int* disc , int* low , int* parent ,bool* ap){


    // A static variable is used for simplicity, 
    // we can avoid the use of static
    // variable by passing a pointer
    static int time = 0;

    // Count of children in DFS Tree
    int children = 0;

    // Mark the current node as visited
    visited[u] = true;

    // Initialize discovery time and low value
    disc[u] = low[u] = ++time;

    // Go through all vertices aadjacent to this
    
    for (auto v:edges[u])
    {
        // v is current adjacent of u

        // If v is not visited yet, then make it a child of u
        // in DFS tree and recur for it
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            dfs(v, visited, disc, low, parent, ap);

            // Check if the subtree rooted with v has a connection to
            // one of the ancestors of u
            low[u]  = min(low[u], low[v]);

            // u is an articulation point in following cases

            // (1) u is root of DFS tree and has two or more chilren.
            if (parent[u] == NIL && children > 1)
               ap[u] = true;

            // (2) If u is not root and low value of one of its child is more
            // than discovery value of u.
            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }

        // Update low value of u for parent function calls.
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }


}

bool* Ap(int n){

    int* disc = new int[n];
    int* low = new int[n];
    int* parent = new int[n];
    bool *ap = new bool[n]();

    for(int i=0;i<n;i++){
        parent[i] = NIL;
        visited[i] = false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i,visited,disc,low,parent,ap);
    }

    delete disc;
    delete low;
    delete parent;
    return ap;
}



int main(){

    int n,m;
    cin>>n>>m;

    for(int i=0;i<MAX;i++) edges[i].clear();
    for(int i=0;i<m;i++){
        int x , y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    bool* ap = Ap(n);
    for(int i=0;i<n;i++)
     {if(ap[i])
      {cout<<i<<" ";}}
    // cout<<endl;

}