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
    triplet ans = extend_euclide(a,m); // a should greater or equal than m;
    return (ans.x%m + m)%m; // avoid negative value by adding (ans%m + m)%m; 

}






int main(){

    ll a, b ,m;
    cin>>a >>m;

    // triplet ans = extend_euclide(max(a,b),min(a,b));

    // cout<<"Gcd of "<<a<<" "<<b<<" is "<<ans.gcd<<endl;
    // cout<<"X "<<ans.x<<endl;
    // cout<<"Y "<<ans.y<<endl;

    cout<<"Modulus Inverse : "<<m_mod_inverse(max(a,m),min(m,a))<<endl;



}
