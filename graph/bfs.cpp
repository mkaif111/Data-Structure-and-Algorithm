#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<T>> edges;
    public:
    void addEdge(T src ,T des){
        edges[src].push_back(des);
        edges[des].push_back(src);
    }
    void bfs(T src){
        unordered_map<T,bool> visited;
        visited[src] = true;
        queue<T> q;
        q.push(src);
        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            for(auto nbr:edges[node]){
                if(!m[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
        cout<<endl;
        return;
    }

};
void bfs(int** edges , int sv, int n, bool* visited){
    queue<int>q;

    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int curr_v = q.front();
        cout<<curr_v+1<<" ";
        q.pop();
        

        for(int i=0;i<n;i++){
            if(curr_v==i)
                continue;
            if(edges[curr_v][i]==1 && visited[i]==false){
                q.push(i);
                visited[i]=true;
            }
        }
        

    }


}

int main(){

    int n,e;
    cin >> n >> e;

   

    
    Graph<int>g;
    while(e--)
    {
        int row,col;
        cin >> row >> col;
        g.addEdge(row,col);
    }
    
    




}