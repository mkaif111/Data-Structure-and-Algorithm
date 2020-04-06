#include<bits/stdc++.h>
using namespace std;

#define Max 1000000
#define ll long long int

ll factorize(ll n , ll k) 
{ 
    ll count = 0; 
  
    // count the number of times 2 divides
    if(n%2==0)
        count++;  
    while (!(n % 2)) { 
        n >>= 1; // equivalent to n=n/2; 
        count++; 
    } 
    
    
  
     
  
    // check for all the possible numbers that can  
    // divide it 
    for (long long i = 3; i <= sqrt(n); i += 2) { 

        if(n%i==0)
            count++; 
        while (n % i == 0) { 
            
            n = n / i; 
        }
       
    } 
  
   
    if (n > 2)  
        count++;

    return count;
} 


int main(){

    
    // vector<ll> v = sieve();
   
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll x=n;
        int ans=0;
        
        
        

        if(factorize(n,k)>=k){
            // cout<<" Yes ";
            ans=1;
        }
    
        cout<<ans<<endl;

        
    }




    // 

}