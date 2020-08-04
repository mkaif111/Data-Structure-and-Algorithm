#include<iostream>
using namespace std;
#define ll long long int
int main() {
	int t; cin>>t;
	while(t--){
	int n; cin>>n;
	ll arr[n],prefix[n+1];
	for(int i=0;i<n+1;i++){
		prefix[i] = 0;
	}
	ll sum=0;
	prefix[0] = 1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
		sum = sum%n;
		sum = (sum+n)%n;
		prefix[sum]++;
	}

	ll ans = 0;
	for(int i=0;i<n;i++){
		ll m = prefix[i];
		ans += (m*(m-1))/2;

	}
	cout<<ans<<endl;
	}
	return 0;
}