#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int prime[100001];

map<ll,int> t_prime(){
    prime[0] = 0;
    for(int i=0;i<=100000;i++){
        prime[i] = i;
    }
    for(int i=0;i<=100000;i++){
        if(prime[i]==i){
            for(int j=i*i;j<=100000;j+=i){
                prime[j] = 1;
            }
        }
    }
    map<ll,int> m;
    for(int i=1;i<=100000;i++){
        if(prime[i]==i){
            ll index = (ll)i*i;
            m[i*i] = 1;
        }
    }

    return m;
    
}

int main(){

   map<ll,int> m =  t_prime();
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        if (m.count(n)>0){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}