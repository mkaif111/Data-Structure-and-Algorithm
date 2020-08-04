#include<bits/stdc++.h>
using namespace std;

void dfs(int s,int e,vector<int> *edges){
    cout<<s<<" ";
    for(auto v:edges[s]){
        if(v!=e)
            dfs(v,s,edges);
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

    dfs(4,4,edges);



}