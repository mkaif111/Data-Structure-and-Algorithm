#include<bits/stdc++.h>
using namespace std;


void dfs(int s,int e,vector<int> *edges){
    cout<<s<<" ";
    for(auto v:edges[s]){
        if(v!=e)
            dfs(v,s,edges);
    }
}
void subtree(int s,int e,vector<int>* edges,int *c){
    c[s] = 1; // node itself subtree at least

    for(auto v : edges[s]){
        if(v==e)
        continue;
        
        subtree(v,s,edges,c);
        c[s]+=c[v];
    }

}

int main(){

    int n;
    cin>>n;
    vector<int> edges[n+1];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int c[n+1];

    dfs(1,0,edges);
    cout<<endl;
    subtree(2,0,edges,c);
    for(int i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
    cout<<endl;



}