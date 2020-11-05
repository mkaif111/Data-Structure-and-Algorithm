#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int k, int x, int y)
{
    if (x % n == y % n)
        return true;
    int end = x % n;
    x = (x + k) % n;
    y = y % n;
    while (x % n != end)
    {
        if (x % n == (y % n))
            return true;
        x = (x + k) % n;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x, y;
        cin >> n >> k >> x >> y;
        if (solve(n, k, x, y))
            cout << "YES" << endl;
        else
        {
            cout << "NO" << endl;
        }
    }
}
