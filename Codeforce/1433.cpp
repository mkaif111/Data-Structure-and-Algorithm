#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int msd = n;
        while(msd>10){
            msd = msd/10;
        }
        int ans = max(0,msd-1)*10;
        int digit = msd;
        int count = 0;
        for(int i=1;i<=4 and msd<=n;i++){
            if(msd<=n){
                count+=i;
            }
            msd = msd*10 + digit;
        }
        ans +=count;
        cout<<ans<<endl;
    }
}