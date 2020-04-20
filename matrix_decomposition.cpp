#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

ll power(ll x, unsigned long long int y)  
{  
    ll res = 1;     // Initialize result  
  
    x = x % mod; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % mod;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % mod;  
    }  
    return res;  
} 

ll power_num(ll a, ll b){
    if (b==0){ return 1;}
    if (b==1){ return a;}

    if(b%2==0){
        int val = power_num(a,b/2)%mod;

        return (val*val)%mod;
    }

    return (a*power_num(a,b-1))%mod;
}

int pow_mod(int a, int b){
    if(b==1){
        return a;
    }
    long long int  ans = 1;

    while(b!=0)
    {
        if(b&1==1){
            ans*=a;
        }
    
    a = (a*a);
    b = b/2; 
    }

    return ans;
}

int main()
{

    int t;
    cin>>t;
     while(t--){
         int n; ll A;
         cin>>n>>A;
        int total_remove = 0;
         ll each_element = A;

         ll sum = 0;
         for(int i=1;i<=n;i++){
            ll remove_element = 2*i-1;

            ll pro=power(A,remove_element);
            //  for(int j=0;j<remove_element;j++)
            //         pro*=A%mod;
            
            // cout<<pro<<" ";
            A=(A*pro)%mod;
            sum = sum%mod + pro%mod;
            // cout<<sum<<endl;
           
         }

        //  cout<<each_element<<endl;

        // sum +=pow_mod(2,n*n);
         cout<<sum%mod<<endl;
     }

}