#include <bits/stdc++.h>
using namespace std;

long long mergeSort(long long arr[], int left, int right)
{

    if (left >= right)
        return 0;
    int m = left + (right - left) / 2;
    long long x = mergeSort(arr, left, m);
    long long y = mergeSort(arr, m + 1, right);
    long long z = merge(arr, left, m, right);

    return (x + y + z);
}

long long int merge(long long arr[], int left, int mid, int right)
{
    int n = right - left + 1;
    long long temp[n];

    int i = left;
    int j = mid + 1;
    int k = 0;
    long long count = 0;
    while (i <= mid and j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            count += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
        temp[k++] = arr[j++];
    for (int i = left; i <= right; i += 1)
        arr[i] = temp[i - left];
    return count;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    if (N < 2)
        return 0;

    return mergeSort(arr, 0, N - 1);
}

int main()
{
    return 0;
}