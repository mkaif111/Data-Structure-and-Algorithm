#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fact(ll t,ll m) {
  ll f=1;
  for(int i=2;i<=t;i++) {
    f=(f%m*i%m)%m;
  }
  return f;
}
int main() {

  int n;
  cin>>n;
  while(n--) {
    ll t,m;
    cin>>t>>m;
    if(t<m) {
      cout<<fact(t,m)<<"\n";
    } else if(t==m) {
      cout<<"1\n";
    } else {
      if((t/m)%2==0) {
        cout<<fact(t%m,m)<<"\n";
      } else {
        cout<<((m-1)*fact(t%m,m))%m<<"\n";
      }
    }
  }
  return 0;
}