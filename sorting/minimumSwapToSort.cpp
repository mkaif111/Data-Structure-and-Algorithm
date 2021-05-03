#include <bits/stdc++.h>
using namespace std;

int minSwapSort(vector<int> nums)
{

    int n = nums.size();
    pair<int, int> p[n];
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++)
    {
        p[i].first = nums[i];
        p[i].second = i;
    }
    sort(p, p + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || p[i].second == i)
            continue;

        int j = i;
        int cycle = 0;
        while (!vis[j])
        {
            vis[j] = true;
            j = p[j].second;
            cycle++;
        }
        ans += (cycle > 0) ? cycle - 1 : 0;
    }

    return ans;
}

int main()
{
    int sizeOfarray;
    cin >> sizeOfarray;
    vector<int> nums(sizeOfarray);
    for (int i = 0; i < sizeOfarray; i++)
    {
        cin >> nums[i];
    }
    int minimumSwap = minSwapSort(nums);
    cout << "Min swaps required : " << minimumSwap << endl;

    return 0;
}