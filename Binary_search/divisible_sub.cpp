#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		ll a[n],pf[n],cnt[n];
		for(int i=0;i<n;i++){
			cin>>a[i];

		}
		for(int i=0;i<n;i++){
			pf[i] = 0;
			cnt[i] = 0;

		}
		pf[0] = ((a[0]%n) + n)%n;
		cnt[0] = 1;
		cnt[pf[0]] = cnt[pf[0]]+1;
		for(int i=1;i<n;i++){
			pf[i] = pf[i-1] + (a[i]%n + n)%n;
			cnt[pf[i]]++;

		}
		ll ans=0;
		for(int i=0;i<n;i++){
			if(cnt[i]>1){
				ll m = cnt[i];
				ans = ans + ((m)*(m-1))/2;
			}

		}

		printf("%lld \n",ans);



		


	}
	return 0;
}