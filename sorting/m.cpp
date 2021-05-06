#include <bits/stdc++.h>
using namespace std;

int mod = 1000000007;
int modFact(int N)
{

    int result = 1;
    for (int i = 1; i <= N; i++)
        result = ((result+mod)%mod * (i+mod)%mod) % mod;


    return (result+mod)%mod;
}

int sol(int N)
{
    if (N <= 3)
        return 0;
    int e = N / 2;
    int o = N-e;
    int emod = modFact(e);
    int omod = modFact(o);
    // cout<<emod<<" "<<omod<<endl;
    int ans = ((emod % mod) * (omod % mod)) % mod;
    // cout<<ans<<endl;
    ans = (ans+mod)%mod;
    ans = (ans % mod * 2%mod) % mod;
    return (ans+mod)%mod;
}

int main()
{
    int n;
    cin >> n;
    cout << sol(n) << endl;

    return 0;
}