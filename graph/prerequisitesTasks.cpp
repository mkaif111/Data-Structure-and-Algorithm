#include <bits/stdc++.h>
using namespace std;

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int find(int i, int parent[])
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i], parent);
    }

    void makeUnion(int u, int v, int parent[])
    {
        int s1 = find(u, parent);
        int s2 = find(v, parent);
        if (s1 != s2)
            parent[s1] = s2;
    }
    bool dfs(vector<vector<int>> g, vector<bool> &visited, vector<bool> &path, int parent, int src)
    {

        if (visited[src])
            return false;
        visited[src] = true;
        path[src] = true;
        for (auto it : g[src])
        {
            if (path[it] || dfs(g, visited, path, src, it))
                return true;
        }
        path[src] = false;
        return false;
    }
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // Code here
        int parent[N + 1];
        for (int i = 0; i <= N; i++)
        {
            parent[i] = i;
        }
        vector<bool> visited(N, false);
        vector<vector<int>> g(N);
        for (auto it : prerequisites)
        {
            g[it.first].push_back(it.second);
        }
        vector<bool> path(N, false);
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                bool ans = dfs(g, visited, path, -1, i);
                if (ans == true)
                    return false;
            }
        }

        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends