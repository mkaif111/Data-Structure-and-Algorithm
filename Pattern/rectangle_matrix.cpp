vector<vector<int>> Solution::prettyPrint(int A)
{
    vector<vector<int>> matrix;
    for (int i = 0; i < A * 2 - 1; i++)
    {
        vector<int> t;
        for (int j = 0; j < A * 2 - 1; j++)
        {
            t.push_back(0);
        }
        matrix.push_back(t);
    }

    for (int i = 1; i <= A * 2 - 1; i++)
    {
        // right
        for (int j = i; j <= A * 2 - i ; j++)
        {
            matrix[i - 1][j - 1] = A - i + 1;
        }
        // down
        for (int j = i; j <= A * 2 - i ; j++)
        {
            matrix[j - 1][i - 1] = A - i + 1;
        }
        //down then rigt
        for (int j = i; j <= A * 2  - i; j++)
        {
            matrix[2 * A - i - 1][j - 1] = A - i + 1;
        }
        //last col down
        for (int j = i; j <= A * 2  - i; j++)
        {
            matrix[j - 1][2 * A - i - 1] = A - i + 1;
        }
    }

    for (auto v : matrix)
    {
        for (auto u : v)
        {
            cout << u << " ";
        }
        cout << endl;
    }

    return matrix;
}
