#include <bits/stdc++.h>
using namespace std;

struct edges {
    int des , src , weight;
    
    edges(){
        des=src=weight=0;
    }
    
};

bool com(edges v1 ,edges v2){
    
    return (v1.weight<v2.weight)?true:false;
}

bool union_algo(int* parent ,int v1 , int v2){
    while(parent[v1]!=v1){
        v1 = parent[v1];
    }
    
     while(parent[v2]!=v2){
        v2 = parent[v2];
    }
    
    return v1!=v2;
}


int main()
{
  int v , e;
  cin >> v >> e;
    
  edges *edge = new edges[e];
    
  for(int i=0;i<e;i++)
  {
      int des,src,weight;
      cin>>src>>des>>weight;
      edge[i].des = des;
      edge[i].src = src;
      edge[i].weight = weight;
      
  }
    
	edges *mst = new edges[v-1];
    int count=0;
    int *parent = new int[v];
    for(int i=0;i<v;i++)
        parent[i]=i;
    
    int i=0;
    
    sort(edge,edge+e,com);
    // for(int i=0;i<v;i++){
    //     cout<<edge[i].des<<" "<<edge[i].src<<" "<<edge[i].weight<<endl;
    // }
    
    while(count!=v-1){
        
        if(union_algo(parent,edge[i].src , edge[i].des))
        {
            mst[count].des = edge[i].des;
            mst[count].weight = edge[i].weight;
            mst[count].src = edge[i].src;
            count++;
            parent[edge[i].des] = edge[i].src;
        }
        
        i++;
    }
    // cout<<"-----------------"<<endl;
    
    for(int i=0;i<count;i++){
        cout<<min(mst[i].src,mst[i].des)<<" "<<max(mst[i].src,mst[i].des)<<" "<<mst[i].weight<<endl;
    }
    
    
    

  

  return 0;
}
