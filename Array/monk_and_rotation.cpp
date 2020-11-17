#include <iostream>
using namespace std;

void reverse(int *arr, int l, int h)
{
    while (l < h)
    {
        swap(arr[l], arr[h]);
        l++;
        h--;
    }
    return;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // Clockwise rotation
        reverse(arr, 0, n - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
        // AntiClockwise rotation
        // reverse(arr,0,k-1);
        // reverse(arr,k,n-1);
        // reverse(arr,0,n-1);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
}