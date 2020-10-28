#include <iostream>
using namespace std;

bool sort_or_not(int arr[], int n, int index)
{
    // checked all elements
    if (n == index)
    {
        return true;
    }
    if (arr[n - 1] < arr[index])
    {
        return false;
    }
    bool ans = sort_or_not(arr, n - 1, index);
    if (ans)
    {
        return sort_or_not(arr, n, index + 1);
    }
    else
    {
        return false;
    }
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
    cout << sort_or_not(arr, n, 0) << endl;
}