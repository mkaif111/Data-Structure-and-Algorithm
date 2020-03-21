#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    
    return (b==0)?a:gcd(b,a%b);
}



int main(){

    ll a, b;
    cin>>a>>b;
    cout<<"Gcd of "<<a<<" "<<b<<" is "<<gcd(max(a,b),min(a,b))<<endl;


}

