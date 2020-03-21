#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

bool config(ll *arr,ll k, ll n, ll ans,ll t){
    ll sum=0;
    ll painter = 1;
    for(int i=0;i<n;i++){
        if(sum+arr[i]*t>ans)
        {
            sum = arr[i]*t;
            painter++;
            if(painter>k)
            {
                return false;
            }

        }
            else{
                sum+=arr[i]*t;
            }
        }
    

    return true;
}

ll bSearch(ll *arr,ll k ,ll n, ll t){
    ll low=0,high=0;
    for(int i=0;i<n;i++){
        high+=arr[i]*t;
        low = max(low,arr[i]);
    }
     if (k == 1){  
        return high; }    
    if ( n == 1)  { 
        return arr[0]*t;}
    low = low*t;
    
    ll fAns=0;
    while(low<=high){
        ll mid = low + (high-low)/2;
        // cout<<mid<<endl;

        if(config(arr,k,n,mid,t)){
            fAns = mid%10000003;
           
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    return fAns;
}

int main() {
	ll n,k,t;
	cin>>n>>k>>t;

	ll* arr = new ll[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	// sort(arr,arr+n);

	// cout<<arr[n-1]*t<<endl;

	

	cout<<bSearch(arr,k,n,t)%10000003<<endl;

    delete arr;
	
	
	return 0;
}