#include <bits/stdc++.h>
using namespace std;

int circularSubarraySum(int arr[], int num)
{

    // your code here

    int maxSum = INT_MIN;
    int tempMaxSum = 0;
    int sum = 0;

    int minSum = INT_MAX;
    int tempMinSum = 0;

    for (int i = 0; i < num; i++)
    {
        tempMaxSum += arr[i];
        maxSum = max(maxSum, tempMaxSum);
        tempMaxSum = max(0, tempMaxSum);
        sum += arr[i];

        tempMinSum += arr[i];
        minSum = min(tempMinSum, minSum);
        tempMinSum = min(0, tempMinSum);
    }

    if (sum == minSum)
        return maxSum;

    return max(maxSum, sum - minSum);
}