#include<bits/stdc++.h>
using namespace std;

bool hasPath(int** edges , int sv, int n, bool* visited , int ev)
{
        if(sv==ev){
            return true;
        }

        queue<int> q;
        q.push(sv);

        while(!q.empty()){
            int curr_v = q.front();

            q.pop();

            if(curr_v==ev)
                return true;

            for(int i=0;i<n;i++){
                if(curr_v == i)
                    continue;
                if( edges[curr_v][i]==1 && !visited[i])
                    {
                        q.push(i);
                        visited[i]=true;
                    }

            }

        }

        return false;


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
    
    
    
  
    if(hasPath(edges,start,n,visited,v))
 
    
    {
        cout<<"true"<<endl;
      
        
    }
    else{
        cout<<"false"<<endl;
    }
    
    
    for(int i=0;i<n;i++){
        delete edges[i];
    }
    
    delete edges;
    delete visited;
     

}