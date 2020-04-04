#include<bits/stdc++.h>
using namespace std;

#define Max 1000001
#define ll long long int


vector<pair<ll,ll>> sieve(){

    vector<pair<ll,ll>> prime(Max,{0,0}); // first--> divisor,  second-->prime_no
    // cout<<prime[5].first<<" "<<prime[5].second<<endl;
    
    prime[1].first = 1;
    prime[1].second = 0;

    for(int i=2;i<=Max;i++){
        
        for(int j=2*i;j<=Max;j=i+j)
        {
            
            prime[j].first=prime[j].first + 1;

            if(prime[i].second==0)
            {
                prime[j].second=prime[j].second + 1;
                
            }

        }
    }
    prime[2].second = 1;
    for(int i=3;i<=Max;i+=2){
        if(prime[i].second==0){
            prime[i].second++;
        }
    }
    
    // cout<<prime[5].first<<" "<<prime[5].second<<endl;

    return prime;


}

int main(){

    
    vector<pair<ll,ll>> v = sieve();
   
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        // int ans=0;
        // for(int i=1;i<=Max;i++){
        //     if(v[i].first+2==n && v[i].second==k)
        //        { ans=1;
        //         break;}
        // }

        cout<<v[n].first+2<<" "<<v[n].second<<endl;
        cout<<v[k].first+2<<" "<<v[k].second<<endl;
    }

    // 

}