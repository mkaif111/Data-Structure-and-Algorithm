#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    // Your code here
    int n = r - l + 1;
    int temp[n];

    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m and j <= r)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= m)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];

    for (int i = l; i <= r; i++)
    {
        arr[i] = temp[i - l];
    }

    return;
}

void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
    return;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}