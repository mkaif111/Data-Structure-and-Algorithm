#include<bits/stdc++.h>


#define MAXN 5000

using namespace std;

vector< int > edges[ MAXN + 1 ], edgesT[ MAXN + 1 ], sorted;
bool visited[ MAXN + 1 ];
// int comp[ MAXN + 1 ], sol[ MAXN + 1 ];
int n, m;

void init( int N ) {
    for ( int i = 0; i <= N; ++i ) {
        edges[ i ].clear();
        edgesT[ i ].clear();
        
    }
	sorted.clear();
}

void dfs1(int u){
    visited[u] = true;
    
    for(auto x:edges[u]){
        if(!visited[x])
            dfs1(x);
    }
    
    sorted.push_back(u);
}

void dfs2(int u ,unordered_set <int>* component){
    component->insert(u);
    visited[u] = true;
    for(int x:edgesT[u]){
        if(!visited[x]){
            
            dfs2(x,component);
        }
    }
}

int main() {
    int  u, v, compon;
    while ( 1 ) {
        scanf( "%d", &n );
        if ( n == 0 ) {
            break;
        }
        scanf( "%d", &m );
        init( n );
        for (int i = 0; i < m; ++i ) {
            scanf( "%d%d", &u, &v );
            edges[ u ].push_back( v );
            edgesT[ v ].push_back( u );
        }
        
        memset(visited , false , sizeof(visited));
        for(int i=1;i<=n;i++){
            if (!visited[i]){
                dfs1(i);
            }
        }
        
        memset(visited , false , sizeof(visited));
        unordered_set<unordered_set<int>*>* output = new unordered_set<unordered_set<int>*>();
        
        for(int i=sorted.size()-1;i>=0;i++){
            if(!visited[sorted[i]]){
                unordered_set<int>* component = new unordered_set<int>();
                dfs2(sorted[i] , component);
                output->insert(component);
                delete component;
            }
            
        }
        
        unordered_set<unordered_set<int>*>:: iterator it1 = output->begin();
        
        
        while(it1!=output->end()){
            bool flag = true;
            unordered_set<int>* comp = *it1;
            unordered_set<int>:: iterator it2 = comp->begin();
            while(it2!=comp->end()){
                for(auto y:edges[*it2]){
                    if(comp->count(y)==0)
                    {
                        flag = false;
                        break;
                    }
                }
                it2++;
            }
            
            unordered_set<int>:: iterator it3 = comp->begin();
            while(it3!=comp->end() && flag){
                printf("%d " , *it3);
                it3++;
            }
            
            it1++;
            delete comp;
        }
        
        
        printf( "\n" );
    }
    
    return 0;
}