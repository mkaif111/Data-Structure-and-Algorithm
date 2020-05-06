#include<bits/stdc++.h>
using namespace std;

int getWV(int* dist , int n, bool* visited){
    int min_v = -1;

    for(int i=0;i<n;i++){
        if(!visited[i] && (min_v==-1 || dist[i]<dist[min_v])){
            min_v = i;
        }
    }

    return min_v;
}

void dj(vector<pair<int,int>>* edges , int n){

    int* dist = new int[n];
    bool* visited = new bool[n]();

    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    for(int i=0;i<n-1;i++){

        int min_v = getWV(dist,n,visited);

        visited[min_v] = true;

        for(auto v:edges[min_v]){
            if(!visited[v.first]){
                
                if(dist[v.first]>dist[min_v]+v.second){
                    dist[v.first] = dist[min_v]+v.second;
                }
            }
        }

    }

    for(int i=0;i<n;i++){
        cout << 0 << " " << i << " " << dist[i] << " \n";
    }

}


int main(){
    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<pair<int,int>> edges[m+1];
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;

        edges[x].push_back(make_pair(y,w));
        edges[y].push_back(make_pair(x,w));
    }

    dj(edges,n);



}