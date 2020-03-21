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



    triplet smallAns = extend_euclide(b,b%a);
    triplet ans;
    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x -(a/b)*smallAns.y;

    return ans;
}

ll gcd(ll a, ll b){
    
    return (b==0)?a:gcd(b,a%b);
}





int main(){

    ll a, b ;
    cin>>a >> b;

    triplet ans = extend_euclide(max(a,b),min(a,b));

    cout<<"Gcd of "<<a<<" "<<b<<" is "<<ans.gcd<<endl;
    cout<<"X "<<ans.x<<endl;
    cout<<"Y "<<ans.y<<endl;



}
