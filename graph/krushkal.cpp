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

int getparent(int v , int* parent){
    if(parent[v]==v){
        return v;
    }
    return getparent(parent[v],parent);
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
   
    while(count!=v-1){
        
        
        int src_parent = getparent(edge[i].src, parent);
        int des_parent = getparent(edge[i].des , parent);
        if(src_parent!=des_parent)
        {	
            
            mst[count] = edge[i];
            count++;
            parent[src_parent] = des_parent;
        }
        
        i++;
    }
    // cout<<"-----------------"<<endl;
    
    for(int i=0;i<count;i++){
        cout<<min(mst[i].src,mst[i].des)<<" "<<max(mst[i].src,mst[i].des)<<" "<<mst[i].weight<<endl;
    }
    
    
    

  

  return 0;
}
