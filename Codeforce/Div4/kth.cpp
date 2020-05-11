#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        ll n,k;
        scanf("%lld %lld",&n,&k);
        if(k<n){
            printf("%lld \n",k);
        }
        else if(k==n){
            printf("%lld \n",n+1);
        }
        else{
            k = k-(n-1);
            ll i=n+1;
            while(k>0){
                if (i%n==0){
                    continue;
                }
                k--;
                i++;

            }
            printf("%lld \n",i);
        }
    }
}