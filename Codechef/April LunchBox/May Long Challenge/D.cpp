#include<bits/stdc++.h>
using namespace std;

#define ll long long int 
#define print printf

ll sol2(ll x,ll y, ll l,ll r){
    
    if(x==0 || y==0)
        return l;
    int count=0;
            ll rcopy = r;

            while(rcopy>0){
                rcopy = rcopy>>1;
                count++;
            }

            ll fixrange = 1<<count;
            fixrange--;
            ll z = (x | y)&fixrange;
            
            ll z_c = (x&fixrange)&(y&fixrange);
            // printf("Z common : %lld\n",z_c);
            
            if(z_c==0)
             return l;
            // if(z<=r)
            //     return z;
            
            ll ans = (x&z)&(y&z);
            ll finalans = z;
            //decrement
            for(int i=0;i<count-1;i++){
                ll m = 1<<i;
                if((z & m)==m){
                    z = z ^ m;
                }
                if(z<=r)
                    break;
            }
            // increment;
            for(int i=count-1;i>=0;i--){
                ll m = 1<<i;
                if((finalans & m)== m && (z | m) <=r)
                    z = z | m;

            }
        

        // ll bans = INT_MIN;
        // ll zz = -1;

        // ll low = l;
        // ll high  = r;

        // while(low<high){
        //     ll mid = (low+high)/2;
        //     ll fake = (x & mid)*(y & mid);
        //     print("low : %lld high : %lld mid : %lld fake : %lld \n",low,high,mid,fake);
           
        //     if(fake>bans){
        //         bans = fake;
        //         zz = mid;
        //         low = mid;
        //     }
        //     else if(fake==0){
        //         high--;
        //     }
        //     else{
        //         high = mid;
        //     }
        // }

        ll ans1 = (x&z)*(y&z);
        ll ans2 = (x&(z-1))*(y&(z-1));
        if(ans2>ans1)
            return z-1;
        if(ans1==0)
            return l;
        return z;

}

ll sol(ll x,ll y, ll l,ll r){
    ll ans =-1;
    ll z = 0;
    for(ll i=l;i<=r;i++){
        ll check = (x & i)*(y & i);
        if(check>ans){
            ans = check;
            z = i;
        }
    }

    return z;
}


int main(){

    int t;
    scanf("%d",&t);

    while(t--){
        ll x,y,l,r;
        scanf("%lld %lld %lld %lld",&x,&y,&l,&r);
        

        ll z = x | y;

        if(z<=r && (x!=0 && y!=0) && z>=l)
            printf("%lld \n",z);
        
        else
        {
           
        ll loopans = sol2(x,y,l,r);
        printf("%lld \n",loopans);

            
        } // else end
        
       
        // ll loopans = sol(x,y,l,r);
        // printf("Loop ans : %lld\n",loopans);

    } // while end
}