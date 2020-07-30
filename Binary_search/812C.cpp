// CodeForces.com --> C. Sagheer and Nubian Market
#include <iostream>
#include <climits>
#include <algorithm>
#include <math.h>
using namespace std;

#define ll long long int

ll calPrice(int k, int price[], int n)
{
    ll ans = 0;
    ll b[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = price[i] + (i + 1) * (ll)k;
    }
    sort(b, b + n);
    for (int i = 0; i < k; i++)
    {
        ans += b[i];
    }
    return ans;
}

void bs(int arr[], int n, int budget)
{
    int low = 0;
    int high = n + 1;
    ll ans = 0;
    while (low < high - 1)
    {
        int mid = (low + high) / 2;
        if (calPrice(mid, arr, n) <= budget)
        {
            ans = calPrice(mid, arr, n);
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    
    cout << low << " " << ans << endl;
}

int main()
{
    int n, budget;
    cin >> n >> budget;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bs(arr, n, budget);
}