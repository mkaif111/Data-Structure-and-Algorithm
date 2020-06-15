#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){

    int t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;

    // ll even[100001]={0};
    // ll odd[100000]={0};
    ll count_even=0;
    ll count_odd = 0;
    
    // ll num = n*n;

    // for(ll i=2;i<=100000;i+=2)
    // {

      
    //         even[count_even] = i;
    //         count_even++;
            
        // cout<<i<<" ";

    // }
    // cout<<endl;
    // for(ll i=1;i<=100000;i+=2)
    // {

      
    //         odd[count_odd] = i;
    //         count_odd++;
    //         // cout<<i<<" ";
        

    // }
    // cout<<endl;
    // for(ll i=0;i<count_odd;i++){cout<<odd[i]<<" ";}
    // cout<<endl;
    // for(ll i=0;i<count_even;i++){cout<<even[i]<<" ";}
    // cout<<endl;

    count_even = 2;
    count_odd = 1;
    for(ll i=0;i<n;i++){
        if(i%2==0){
            for(ll j=0;j<n;j++)
            {
                if(j%2==0){
                    cout<<count_odd<<" ";
                    count_odd+=2;
                }
                else{
                    cout<<count_even<<" ";
                    count_even+=2;
                }
            }
        }

        else
        {
            for(ll j=0;j<n;j++)
            {
                if(j%2!=0){
                    cout<<count_odd<<" ";
                    count_odd+=2;
                }
                else{
                    cout<<count_even<<" ";
                    count_even+=2;
                }
            }


        }

        cout<<endl;
    }

    }

}
