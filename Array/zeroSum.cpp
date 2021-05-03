#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll findSubarray(vector<ll> arr, int n)
{
    //code here
    unordered_map<int, int> m;
    ll prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        m[prefixSum]++;
    }
    ll ans = 0;
    m[0]++;
    for (auto it : m)
    {
        if (it.second > 1)
        {
            ans += (it.second * (it.second - 1)) / 2;
        }
    }

    return ans;
}