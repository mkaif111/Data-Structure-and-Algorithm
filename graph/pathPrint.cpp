#include<bits/stdc++.h>
using namespace std;

void print_stack(stack<int>s){

    while(!s.empty())
    {
        int x = s.top();
        cout<<x<<" ";
        s.pop();
    }

    return ;
}

void pathPrint(int** edges , int start , int end , int n,bool* visited ,stack<int> s, bool flag){
    
    if(start==end){
        if(visited[start]==false)
            s.push(start);

        print_stack(s);
        flag=true;
        return ;
    }
    
    visited[start] = true;
    s.push(start);

    for(int i=0;i<n;i++){
        if(start==i)
            continue;
        
        if(edges[start][i]==1 && visited[i]==false && flag==false){
            
            pathPrint(edges,i,end,n,visited,s,flag);
        }

    }

    s.pop();
    
    return ;


    
    }






int main()
{
    int n,e;
    cin>>n>>e;

    int** edges = new int*[n];

    for(int i=0;i<n;i++){
        edges[i] = new int[n];

        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }


    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[s][f] = 1;
        edges[f][s] = 1;

    }

    bool* visited = new bool[n];
    
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    int start,v;
    cin>>start>>v;
    
    bool flag = false;
    stack<int> s;
    queue<int>q;
    pathPrint(edges,start,v,n,visited,s,flag);
    cout<<endl;
 
  
   
    
    
    for(int i=0;i<n;i++){
        delete edges[i];
    }
    
    delete edges;
    delete visited;
     

}