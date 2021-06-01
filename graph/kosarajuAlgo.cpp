#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find number of strongly connected components in the graph.
    void dfs(vector<int> adj[], vector<bool> &visited, vector<int> &stack, int src, bool add_stack)
    {

        visited[src] = true;
        for (auto nbr : adj[src])
        {
            if (!visited[nbr])
                dfs(adj, visited, stack, nbr, add_stack);
        }
        if (add_stack)
            stack.push_back(src);
    }

    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> rev[V];
        for (int i = 0; i < V; i++)
        {
            for (auto nbr : adj[i])
            {
                rev[nbr].push_back(i);
            }
        }

        vector<bool> visited(V);
        vector<int> stack;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(adj, visited, stack, i, true);
        }
        for (int i = 0; i < V; i++)
            visited[i] = false;
        int count = 0;
        for (int i = stack.size() - 1; i >= 0; i--)
        {

            if (!visited[stack[i]])
            {
                count++;
                dfs(rev, visited, stack, stack[i], false);
            }
        }

        return count;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends