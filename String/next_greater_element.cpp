#include <bits/stdc++.h>
using namespace std;
string solve(string A)
{
    int n = A.size();

    int i;
    for (i = n - 1; i > 0; i--)
    {
        if (A[i] > A[i - 1])
        {
            break;
        }
    }

    if (i == 0)
        return "-1";

    int smallest = i;
    for (int j = i + 1; j < n; j++)
    {
        if (A[j] > A[i - 1] and A[j] < A[smallest])
            smallest = j;
    }
    swap(A[i - 1], A[smallest]);
    string ans = A.substr(i);
    sort(ans.begin(), ans.end());
    for (int j = 0; j < ans.size(); j++)
    {
        A[i] = ans[j];
        i++;
    }

    return A;
}
