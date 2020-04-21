#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


ll power(ll x, unsigned long long int y)  
{  
    ll res = 1;     // Initialize result  
  
    x = x; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x);  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x);  
    }  
    return res;  
} 



int main()
{

    

        int t;
        cin>>t;

        while(t--){
           
            ll n;
            cin>>n;
            ll ans=1;

            for(ll i =2;i<=sqrt(n);i++){
                ll m = power(2,i)-1;
                if ( n%m == 0)
                {
                    ans = n/m;
                    break;
                }
            }

            cout<<ans<<endl;
            
        }

}


