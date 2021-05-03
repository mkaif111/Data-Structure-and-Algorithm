#include <bits/stdc++.h>
using namespace std;

void rearrange(long long *arr, int n)
{

    // Your code here
    int minIndex = 0;
    int maxIndex = n - 1;
    int mx = arr[maxIndex] + 1;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            arr[i] += (arr[maxIndex--] % mx) * mx;
        }
        else
        {
            arr[i] += (arr[minIndex++] % mx) * mx;
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] /= (mx);
    }
}