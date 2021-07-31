// https://leetcode.com/contest/biweekly-contest-56/problems/nearest-exit-from-entrance-in-maze/
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> d(n, vector<int>(m, -1));
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        q.push({entrance[0], entrance[1]});
        d[entrance[0]][entrance[1]] = 0;
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (d[r][c] != 0)
            {
                if (r == n - 1 or r == 0 or c == m - 1 or c == 0 and maze[r][c] == '.')
                    return d[r][c];
            }
            for (int i = 0; i < 4; i++)
            {
                int x = r + dx[i];
                int y = c + dy[i];

                if (x >= 0 and x < n and y >= 0 and y < m and d[x][y] == -1 and maze[x][y] == '.')
                {
                    d[x][y] = d[r][c] + 1;
                    q.push({x, y});
                }
            }
        }

        return -1;
    }
};