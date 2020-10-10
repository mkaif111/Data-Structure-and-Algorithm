#include <iostream>
using namespace std;

int partision(int *arr, int s, int e)
{
    int i = s - 1;
    int j = s;
    int pivot = arr[e];
    for (; j < e; j++)
    {
        if (arr[j] <= pivot)
        {
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[e], arr[i + 1]);
    return i + 1;
}

void qs(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partision(arr, s, e);
    qs(arr, s, p - 1);
    qs(arr, p + 1, e);
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
    qs(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}