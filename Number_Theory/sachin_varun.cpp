#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

struct triplet{
    ll gcd;
    ll x;
    ll y;
};

triplet extend_euclide(ll a, ll b){
    if(b==0){
        triplet ans;
        ans.gcd = a;
        ans.y = 0;
        ans.x = 1;

        return ans;
    }



    triplet smallAns = extend_euclide(b,a%b);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x -(a/b)*smallAns.y;

    return ans;
}

ll gcd(ll a, ll b){
    
    return (b==0)?a:gcd(b,a%b);
}

ll m_mod_inverse(ll a, ll m){
    triplet ans = extend_euclide(max(a,m),min(a,m)); // a should greater or equal than m;
    return (ans.x%m + m)%m;

}






int main(){

    int t;
    cin>>t;
    
    while(t--){
        
        ll a , b, d;
        cin>>a >>b >>d;
        
        ll g = gcd(max(a,b),min(a,b));
        
        if(d%g!=0){
            cout<<0<<endl;
            continue;
        }
        
        if(d==0){
            cout<<1<<endl; // one solution x=0,y=0
            continue;
        }
        
        a /=g;
        b /=g;
        d /=g;
        
        ll y1 = ((d%a)*m_mod_inverse(b,a))%a;
        
        if(d<y1*b){
            cout<<0<<endl;
            continue;
        }
        
        ll firstV = d/b;
        
        ll n = (firstV-y1)/a;
        
        cout<<n+1<<endl;
        
        
        
        
    }



}
