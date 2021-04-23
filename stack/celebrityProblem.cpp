#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>> &matrix, int n)
{
    // code here
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    int A = s.top();
    s.pop();
    int B = s.top();
    s.pop();

    while (s.size() > 1)
    {
        if (matrix[A][B] == 1)
        {
            A = s.top();
            s.pop();
        }
        else
        {
            B = s.top();
            s.pop();
        }
    }
    // if there is only two candidate.
    if (s.empty())
    {
        if (matrix[A][B] && matrix[B][A] == 0)
            return B;
        if (matrix[B][A] && matrix[A][B] == 0)
            return A;
        return -1;
    }
    
    int C = s.top();
    s.pop();
    if (matrix[C][B])
        C = B;
    if (matrix[C][A])
        C = A;
    // cout<<C<<endl;
    for (int i = 0; i < n; i++)
    {
        if ((matrix[C][i] == 1 || matrix[i][C] == 0) && i != C)
            return -1;
    }

    return C;
}