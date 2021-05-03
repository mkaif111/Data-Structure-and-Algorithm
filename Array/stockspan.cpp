#include <bits/stdc++.h>
using namespace std;
vector<int> calculateSpan(int price[], int n)
{
    // Your code here
    stack<pair<int, int>> s;
    s.push({price[0], 1});
    vector<int> ans;
    ans.push_back(1);
    for (int i = 1; i < n; i++)
    {
        int p = 1;
        while (s.empty() == false and price[i] >= s.top().first)
        {
            p += s.top().second;
            s.pop();
        }
        ans.push_back(p);
        s.push({price[i], p});
    }

    return ans;
}