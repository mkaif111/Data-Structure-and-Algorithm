#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
#define ll long long int
ll zeroSumSubarrays(vector<ll> arr, int n, int target)
{

    int count = 0;
    ll sum = 0;
    unordered_map<ll, ll> m;
    for (auto it : arr)
    {
        sum += it;
        if (sum == target)
            count++;
        if (m.find(sum - target) != m.end())
            count += m[sum - target];
        m[sum]++;
    }

    return count;
}