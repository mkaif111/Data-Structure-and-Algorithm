#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define f first
#define s second
#define mk make_pair
#define pb push_back
#define PII pair<int,int>


int main(){

    int n,i,j;
    ll k,x,ans=0;

    cin>>n>>k;

    x=k;

    vector<ll>a(n);

    for(i=0;i<n;i++) cin>>a[i];
    vector<PII> vp;

    for(i=2;i*i<=x;i++){
        if(x%i==0){
            int cn=0;

            while(x%i==0){
                x/=i;
                cn++;
            }

            vp.pb(mk(i,cn));
        }
    }

    if(x!=1){
        vp.pb(mk(x,1));
    }

    vector<PII> vq = vp;
    for(int i=0;i<vq.size();i++){
        vq[i].s = 0;
    }

    j=0; // i ans j are two pointer;

    for(i=0;i<n;i++){

        for(int z=0;z<vp.size();z++)
        {
            if(a[i]%vp[z].f==0){
                x = a[i];
                int cn=0;
                while(x%vp[z].f==0){
                    x /=vp[z].f;
                    cn++;
                }
                vq[z].s +=cn;
            }
        }

        while(j<=i)
        {
            int z;
            for(z=0;z<vp.size();z++){
                if(vp[z].s>vq[z].s) break;
            }

            if(z!=vp.size()) break;

            ans+=n-i;
            //remove factors of a[j] from vq
            for(int z=0;z<vp.size();z++)
            {
                if(a[j]%vp[z].f==0)
                {
                    x = a[j];
                    int cn=0;
                    while(x%vp[z].f==0){
                        x/=vp[z].f;
                        cn++;
                    }
                    vq[z].s -=cn;
                }
            }
            j++;
        }


    }

    cout<<ans;
}