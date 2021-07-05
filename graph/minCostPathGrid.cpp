// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.
    int dfs(vector<vector<int>> grid, vector<vector<bool>> &visited, int r, int c)
    {
        // cout<<r<<" "<<c<<endl;
        if (r == grid.size() - 1 and c == grid[0].size() - 1)
            return grid[r][c];
        if (r < 0 or r >= grid.size() or c >= grid[0].size() or c < 0 or visited[r][c])
            return INT_MAX;
        visited[r][c] = 1;
        int curr = INT_MAX;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int x = r + dx[i];
            int y = c + dy[i];
            if (x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size() or visited[x][y])
                continue;
            curr = min(curr, dfs(grid, visited, x, y));
            cout << curr << endl;
        }
        if (curr == INT_MAX)
            return curr;
        return grid[r][c] + curr;
    }
    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();
        int m = grid[0].size();

        int dis[n][m];
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dis[i][j] = INT_MAX;
            }
        }

        set<vector<int>> s;
        s.insert({0, 0, 0});
        dis[0][0] = grid[0][0];
        while (!s.empty())
        {

            auto it = *(s.begin());
            s.erase(s.begin());
            for (int i = 0; i < 4; i++)
            {
                int x = it[1] + dx[i];
                int y = it[2] + dy[i];

                if (x < 0 or x >= n or y < 0 or y >= m)
                    continue;

                if (grid[x][y] + dis[it[1]][it[2]] < dis[x][y])
                {
                    if (dis[x][y] != INT_MAX)
                    {
                        s.erase(s.find({dis[x][y], x, y}));
                    }
                    dis[x][y] = dis[it[1]][it[2]] + grid[x][y];
                    s.insert({dis[x][y], x, y});
                }
            }
        }

        return dis[n - 1][m - 1];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends