#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second > p2.second;
    }
    vector<int> sortByFreq(int arr[], int n)
    {
        //Your code here
        unordered_map<int, int> m;
        vector<int> ans;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            m[arr[i]]++;
        }
        copy(m.begin(), m.end(), back_inserter(v));

        sort(v.begin(), v.end(), Solution::comp);

        for (auto it : v)
        {
            for (int i = 0; i < it.second; i++)
                ans.push_back(it.first);
        }

        //  reverse(ans.begin(),ans.end());
        return ans;
    }
};