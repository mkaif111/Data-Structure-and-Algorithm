#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define print printf
// #define for(i,n) for(int i=0;i<n;i++)

bool sign(ll x){
    return x<0;
}
int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll sum = 0;
        for(int i=0;i<n;i++){

            ll x = arr[i];
            
            int j=i;
            while(j<n && sign(arr[i])==sign(arr[j]))
            {   
               
                x = max(arr[j],x);
                j++;

            }
            i = j-1;
            sum+=x;




        }
        print("%lld \n",sum);
        
    }

}