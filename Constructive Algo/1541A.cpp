// Ques : https://codeforces.com/problemset/problem/1541/A
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n % 2 == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i % 2 == 0)
                    cout << i - 1 << " ";
                else
                    cout << i + 1 << " ";
            }
            cout<<endl;
        }
        else
        {
            cout << 3 << " " << 1 << " " << 2 << " ";
            for (int i = 1; i <= n - 3; i++)
            {
                if (i % 2 == 0)
                    cout << i + 2 << " ";
                else
                    cout << i + 4 << " ";
            }
            cout<<endl;
        }
    }
}