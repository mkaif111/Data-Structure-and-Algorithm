#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
const int ma = 1e6+5;
ll mod = 1e9+7;
ll f[ma];
ll modular(ll a, ll b)
{
  ll ans=1;
  while(b)
  {
    if(b%2)
    {
      ans*=a;
      ans%=mod;
    }
    a*=a;
    a%=mod;
    b/=2;
  }
  return ans;
} 
int main()
{
  
  int t;
  f[0]=1;
  for(int i=1;i<=1e6;i++)
    f[i] = f[i-1]*i, f[i]%=mod;
  for(cin>>t;t;--t)
  {
    
    ll n,k;
    cin>>n>>k;
   
    ll inv = modular((f[k]*f[n-k])%mod, mod-2 );
    cout<<(((f[n]*inv)%mod) * (modular(2,k)))%mod<<endl; 
  }
  return 0;
}