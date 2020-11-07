#include <iostream>
using namespace std;

void solve(int col[], int d1[], int d2[], int &ans, int n, int r)
{
    if (r == n)
    {
        ans++;
        return;
    }
    for (int c = 0; c < n; c++)
    {
        if (!(col[c]) and !(d1[r + c]) and !(d2[r - c + n - 1]))
        {
            col[c] = d1[r + c] = d2[r - c + n - 1] = 1;
            solve(col, d1, d2, ans, n, r + 1);
            col[c] = d1[r + c] = d2[r - c + n - 1] = 0;
        }
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    int d1[n * n] = {0};
    int d2[n * n] = {0};
    int col[n] = {0};
    int ans = 0;
    solve(col, d1, d2, ans, n, 0);
    cout << ans << endl;
}