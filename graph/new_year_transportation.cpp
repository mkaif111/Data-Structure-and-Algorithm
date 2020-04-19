#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mx 5000
vector<int> edges[mx];
bool visited[5000];

bool bfs(vector<int>* edges , int n, int end,int start){
    if(start==end){
        return true;
    }
    visited[start] = true;
    queue<int> q;
    q.push(start);
    
    while(!q.empty()){
        
        int curr = q.front();
        q.pop();
        if(curr==end){
            return true;
        }
        
        for(auto i : edges[curr]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
        
        
    }
    
    
    return false;
    
    
}


int main()
{
	//code
    int n,t;
    cin>>n>>t;
    
    int arr[n];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    
    for(int i=0;i<n;i++) edges[i].clear();
    memset(visited,false,sizeof(visited));
    
    //Important part
    for(int i=0;i<n-1;i++){
        edges[i].push_back(i+arr[i]);
    }
    
    bool ans = bfs(edges,n,t-1,0);
    
    string res = (ans)?"YES":"NO";
    
    cout<<res<<endl;
    
	return 0;
}
