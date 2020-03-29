#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll sol(ll a, string b, ll m){
    
    ll res = 1;
    
    
    for(int i =b.length()-1;i>=0;i--){
        
        
        
        if(b[i]=='1'){
            res=res*a;
        }
        if(b[i]=='2'){
            res=(((res%m)*(a%m))%m*(a%m))%m;
            
        }
        
        res = res%m;
        
        a =(((a*a)%m)*(a%m))%m;;
        
        
    }
    
  
    return res;
}


int main() {

	// Write your code here
    int t;
    cin>>t;
    while(t--){
    ll a,m;
    string b;
    cin>>a>>b>>m;
    
   
        // cout<<r<<" base 3"<<endl;
        
        cout<<sol(a,b,m)<<endl;
        
    }
    
    
    
    
}