#include<vector>
#include<unordered_set>
#include<iostream>
#include<stack>
using namespace std;

bool bipartite(vector<int>* edges , int n, int start,bool* visited){
    if(n==0){
        return true;
    }
    visited[start] = true;
    unordered_set<int> set[2];
    set[0].insert(start);
    stack<int> pending;
    pending.push(start);

    while(pending.size()!=0){
        int currentVertex = pending.top();
        pending.pop();

        int set_no = set[0].count(currentVertex)>0?0:1;
        for(int i=0;i<edges[currentVertex].size();i++){
            int neighbour = edges[currentVertex][i];
            if(set[0].count(neighbour)==0 && set[1].count(neighbour)==0 ){
                set[1-set_no].insert(neighbour);
                pending.push(neighbour);
            }
            else if(set[set_no].count(neighbour)>0)
                    return false;
        }

    }

    return true;
}


int main(){

    while(true){
        int n;cin>>n;
        if(n==0)
            break;

        vector<int>* edges = new vector<int>[n];
        int m;cin>>m;

        for(int  i=0;i<m;i++){
            int x, y;
            cin>>x>>y;
            edges[x-1].push_back(y);
        }
        bool* visited = new bool[n]();
        bool flag = true;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                flag = bipartite(edges , n , i , visited);
                if(!flag)
                    break;
            }
        }

        if(flag)
            cout<<"Bipartite"<<endl;
        else
            cout<<"UnBipartite"<<endl;
    }
}