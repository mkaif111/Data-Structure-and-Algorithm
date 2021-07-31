******************************************************************************* /
#include <bits/stdc++.h>
    using namespace std;

void sol(int arr[], int n, int k)
{

    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(abs(arr[i] - k)) != m.end())
        {
            cout << arr[i] << " " << abs(arr[i] - k) << endl;
            count++;
        }
        m[arr[i]]++;
    }
    cout << count << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    sol(arr, n, k);
}
