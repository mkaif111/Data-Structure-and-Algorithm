// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        set<pair<int,int>> s;
        s.insert({0,S});
        while(!s.empty()){
            auto it = *(s.begin());
            int nodeDist = it.first;
            int node = it.second;
            s.erase(s.begin());
            for(auto nbr:adj[node]){
                if(nodeDist + nbr[1]< dist[nbr[0]]){
                    
                    auto p = s.find({dist[nbr[0]],nbr[0]});
                    if(p!=s.end())
                        s.erase(p);
                    dist[nbr[0]] = nodeDist + nbr[1];
                    s.insert({dist[nbr[0]],nbr[0]});
                    
                }
            }
        }
        
        return dist;
        
        
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends