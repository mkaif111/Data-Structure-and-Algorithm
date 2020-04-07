#include <bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> print(int** edges,int n,int start,int end,bool *visited){
   
    if(start==end)  //checking if we are standing at end node
    {
         vector<int> v;
        v.push_back(end);
        return v;
    }
    //ans1.push_back(start);
    visited[start]=true;
    
    for(int i=0;i<n;i++){
       if(edges[start][i]==1&&visited[i]!=1)
        {
            vector<int> v;
            v=print(edges,n,i,end,visited);
            if(v.size()!=0)
            {   
                v.push_back(start);
                return v;
            }
                
            
       }
    }
 vector<int> v;
    return v;     // if no path empty vector will return
}

int main()
{
    int V,E;
    cin>>V>>E;
    int** edges=new int*[V];
    for(int i=0;i<V;i++){
        edges[i]=new int[V];
        for(int j=0;j<V;j++)
            edges[i][j]=0;
    }
    for(int i=0;i<E;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    int start,end;
    cin>>start>>end;
    bool *visited=new bool[V](); // declare/ initislise visited arry
  //  vector<int> ans1;
    vector<int> ans=print(edges,V,start,end,visited);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
   /* if(ans==1){
        for(int i=ans1.size()-1;i>=0;i--){
            cout<<ans1[i]<<" ";
        }
    }
    else{
        cout<<""<<endl;
    }*/

  return 0;
}