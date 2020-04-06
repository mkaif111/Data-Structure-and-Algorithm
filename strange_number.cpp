#include<bits/stdc++.h>
using namespace std;

#define Max 1000000
#define ll long long int

ll factorize(ll n , ll k) 
{ 
    ll count = 0; 
  
    // count the number of times 2 divides
      
    while (!(n % 2)) { 
        n >>= 1; // equivalent to n=n/2; 
        count++;
    } 
    
    
  
     
  
    // check for all the possible numbers that can  
    // divide it 
    for (long long i = 3; i <= sqrt(n); i += 2) { 

        if(n%i==0){   
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        }
        }
       
    } 
  
   
    if (n > 2)  
        count++;

    return count;
} 


int main(){

   
    int t;
    cin>>t;

    while(t--){
        ll n,k;
        cin >> n >> k;
        
        int ans=0;
        
        
        

        if((ll)factorize(n,k)>=k)
            ans = 1;
    
        cout<<ans<<endl;

        
    }




    // 

}