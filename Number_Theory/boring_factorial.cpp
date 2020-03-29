#include<bits/stdc++.h>
using namespace std;
#define ll long long int





ll mex(ll a, ll b, ll c){

    long long int  ans = 1;

    while(b!=0)
    {
        if(b&1==1){
            ans*=a%c;
        }
    
    a = (a*a)%c;
    b = b/2; // binary--> if it is 1001 it become --> 100 right shift basically
}


    return ans%c;
}

ll sol(ll n, ll p){
    ll resi = 1;

    for(ll i=n+1;i<p;i++){
        resi *=mex(i,p-2,p)%p;
    }

    return (p-resi)%p;
}

int main(){

    int t;
    cin>>t;

    while(t--){

        ll n , p;
        cin>>n>>p;

        cout<<(sol(n,p)+p)%p<<endl;


    }


}