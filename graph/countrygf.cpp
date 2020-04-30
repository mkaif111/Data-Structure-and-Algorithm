#include<bits/stdc++.h>
using namespace std;


int bfs(vector<int>* edge , int start , int end,int n){
    if(start==end) return 1;
    bool* visited = new bool[n]();
    visited[1]=true;
    int count=0;
    queue<int> q;
    q.push(1);
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        visited[curr]=true;
        if(curr==end)
            return count;
        for(auto x:edge[curr]){
            if(!visited[x])
            {
                count++;
                if(x==end) 
                {return count;}
                q.push(x);
                visited[x] = true;
            }
        }

    }
    
    return INT_MAX;

}

int main(){
    int n;
    cin>>n;

    vector<int> edge[n+1];
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    int q;
    cin>>q;
    int girls[q+1];
    for(int i=0;i<q;i++){
        cin>>girls[i];
    }

    sort(girls,girls+q);
    
    // cout<<"---------------------\n";
    int min = INT_MAX;
    int ans=0;
    for(int i=0;i<q;i++){
        int curr_min = bfs(edge,1,girls[i],n);
        // cout<<curr_min<<" ----- "<<endl;
        if(curr_min<min){
            min=curr_min;
            ans=girls[i];}
    }

    cout<<ans<<endl;
    // cout<<min<<endl;

}