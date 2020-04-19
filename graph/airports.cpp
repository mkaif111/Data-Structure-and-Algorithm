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
int find_parent(int n, int* parent){
    if(n==parent[n])
        return n;
    
    parent[n] = find_parent(parent[n] , parent);
    return parent[n];
}




void union_algo( int x , int y , int* parent , int* rank)
{
    
    int x_rep = find_parent(x , parent), y_rep = find_parent(y , parent);
    if(x_rep == y_rep) return ;
    
    if(rank[x_rep]<rank[y_rep]) {parent[x_rep] = y_rep;}
    else if(rank[y_rep]<rank[x_rep]) {parent[y_rep] = x_rep;}
    else {parent[y_rep] = x_rep; rank[x_rep]++;}
    
}


int main()
{
    
  int t;
  cin>>t;
    
  for(int num=1;num<=t;num++){
    
  int v , e , A;
  cin >> v >> e>>A;
    
  edges *edge = new edges[e];
    
  for(int i=0;i<e;i++)
  {
      int des,src,weight;
      cin>>src>>des>>weight;
      edge[i].des = des;
      edge[i].src = src;
      edge[i].weight = weight;
      
  }
    
	
    int count=0;
    int *parent = new int[v+1];
    int *rank = new int[v+1];
    for(int i=0;i<v+1;i++)
        {parent[i]=i;
        rank[i]=0;}
      
    
    int i=0;
    
    sort(edge,edge+e,com);
   
    int res=0;
    while(count!=v-1 && i<e){
        
        int x = find_parent(edge[i].src,parent);
        int y = find_parent(edge[i].des,parent);
        
        
        if( x!=y && edge[i].weight<A)
        {
            
            res+=edge[i].weight;
            union_algo(x,y,parent,rank);  
            count++;
           
        }
        
        i++;
    }
 
  int airport=0;
     for(int i=1;i<v+1;i++){
       
         if(parent[i]==i)
             airport++;
     }
  
    
      res = res + airport*A;
  	
    cout<<"Case "<<"#"<<num<<":"<<" "<<res<<" "<<airport<<endl;
    
  }
  

  return 0;
}
