#include<bits/stdc++.h>
using namespace std;

int helper(int s, vector<int> adj[],bool vis[],int parent)
{
    if(parent==-1) parent=s;
    vis[s]=true;
    for(int i : adj[s])
    {
        if (!vis[i]){
            if (helper(i,adj,vis,s)){return i;}
        }
        else if(i!=parent or i==s){return i;}
    }
    return -1;
}

int Cyclic(vector<int> adj[], int V)
{
   // Your code here
   bool* vis = new bool[V];
   for(int i=0;i<V;i++)
   {
       vis[i]=false;

   }
   for(int i=0;i<V;i++){
       if(!vis[i]){
       if(helper(i,adj,vis,-1)){return true;}
       }
   }
   return -1;


}


int main() {

  int t;
  cin>>t;
  while(t--)
  {
    int V , E ;
    cin>>V>>E;
    vector<int> adj[V];
    int u,v;

    for(int i=0;i<E;i++)
    {

      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    bool* vis = new bool[V];
    for(int i=0;i<V;i++)
    {
        vis[i]=false;

    }
    int curr=0;
    int x=-1;
    for(int i=0 ; i<V;i++){
      if (!vis[i]){
        x=helper(i,adj,vis,-1);
      }
      if (x<=curr){ curr =x;}
    }
    cout<<curr<<endl;

  }

  return 0;
}
