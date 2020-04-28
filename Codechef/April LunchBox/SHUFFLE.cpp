#include <bits/stdc++.h>
using namespace std;
int a[100001];
int b[100001];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // freopen("output.txt", "w", stdout);

	int t;
	cin>>t;
	
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    for(int i=1;i<=n;i++){
	        cin>>a[i];
	        b[i]=a[i];
	    }
	    for(int i=1;i<=k;i++){
	        vector<int> v;
	        for(int j=i;j<=n;j+=k){
	            v.push_back(a[i]);
	        }
	        
	        sort(v.begin(),v.end());
	        int idx=0;
	        for(int j=i;j<=n;j+=k)
	        {
	            a[j]=v[idx++];
	        }
	    }
	    for(int i=1;i<=k;i++){
	        vector<int> v;
	        for(int j=i;j<=n;j+=k){
	            v.push_back(b[i]);
	        }
	        
	        sort(v.begin(),v.end(),greater<int>());
	        int idx=0;
	        for(int j=i;j<=n;j+=k)
	        {
	            b[j]=v[idx++];
	        }
	    }
	    
	    bool flag = true;
	    string ans="yes";
	    
	    b[0] = INT_MAX;
	    a[0] = INT_MIN;
	    
	    for(int i=1;i<=n;i++){
	        if(a[i]<a[i-1]){ flag=false;ans="no";break;}
	    }
	    if(flag){
	        cout<<"yes"<<endl;;
	    }
        else{
            for(int i=1;i<=n;i++){
	        if(b[i]>b[i-1]){ans="no";break;}
            
	    
	        cout<<ans<<endl;}
	    }
	        
	    
	    
	}
	
	return 0;
}
