#include <iostream>
#include <vector>
using namespace std;

bool solveMaze(vector<vector<char>> maze, vector<vector<int>> &board, int n, int m, int i, int j)
{
    // base case
    if (i == n - 1 and j == m - 1)
    {
        board[i][j] = 1;
        return true;
    }
    if (i >= n or j >= m)
    {
        return false;
    }
    if (i < 0 or j < 0)
    {
        return false;
    }
    if (maze[i][j] != 'O' or board[i][j] == 1)
    {
        return false;
    }

    board[i][j] = 1;

    bool right = solveMaze(maze, board, n, m, i, j + 1);

    if (right)
    {
        return true;
    }

    bool down = solveMaze(maze, board, n, m, i + 1, j);

    if (down)
    {
        return true;
    }

    bool up = solveMaze(maze, board, n, m, i - 1, j);
    if (up)
        return true;

    board[i][j] = 0;
    bool left = solveMaze(maze, board, n, m, i, j - 1);
    if (left)
        return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m, 'O'));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            maze[i][j] = c;
        }
    }
    vector<vector<int>> board(n, vector<int>(m, 0));
    bool ans = solveMaze(maze, board, n, m, 0, 0);
    if (ans)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "NO PATH FOUND" << endl;
    }

    return 0;
}