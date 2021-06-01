#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<int> adj[], vector<bool> &visited, int v, vector<int> &ans)
    {
        visited[v] = true;
        for (auto it : adj[v])
        {
            if (!visited[it])
            {
                dfs(adj, visited, it, ans);
            }
        }

        ans.insert(ans.begin(), v);
        return;
    }
    //Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[])
    {
        // code here
        vector<int> ans;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(adj, visited, i, ans);
        }

        return ans;
    }
};


