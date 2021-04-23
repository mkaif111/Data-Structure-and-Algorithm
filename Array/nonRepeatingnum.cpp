#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int> nums)
{
    // Code here.
    int xxor = 0;
    for (auto it : nums)
    {
        xxor ^= it;
    }

    // get first set rightmost bit
    int rmb = xxor & (-xxor);
    int zero = 0;
    int one = 0;

    for (auto it : nums)
    {
        if (it & rmb)
            zero ^= it;
        else
            one ^= it;
    }

    vector<int> ans;
    ans.push_back(one);
    ans.push_back(zero);

    sort(ans.begin(), ans.end());

    return ans;
}