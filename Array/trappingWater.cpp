#include <bits/stdc++.h>
using namespace std;

int trappingWater(int arr[], int n)
{
    // Code here
    int leftMax[n];
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(arr[i], leftMax[i - 1]);
    }
    int rightMax[n];
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(arr[i], rightMax[i + 1]);
    }
    int ans = 0;
    for (int i = 0; i < n; i += 1)
    {
        ans += max(0, min(rightMax[i], leftMax[i]) - arr[i]);
    }

    return ans;
}