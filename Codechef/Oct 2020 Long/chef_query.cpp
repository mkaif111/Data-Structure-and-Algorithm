#include <iostream>
using namespace std;
#define ll long long int 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll k;
        cin >> k;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll sum = 0;
        ll ans = -1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum < k)
            {
                ans = i + 1;
                break;
            }
            sum -= k;
            // cout<<sum<<" ";
        }

        if (ans == -1)
        {
            ans = n + (sum / k) + 1;
        }
        cout << ans << endl;
    }

    return 0;
}