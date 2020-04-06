#include<bits/stdc++.h>
using namespace std;

#define Mod 1000000007
#define ll long long int

int main(){


    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        ll *arr = new ll[n];
        int count_zero=0;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            
        }
        
        sort(arr,arr+n,greater<int>());
        ll count=0;
        for(int i=0;i<n;i++)
        {   
            sum =(sum%Mod + max(arr[i]-count,0ll)%Mod)%Mod;
            count++;
        }

        cout<<(sum+Mod)%Mod<<endl;

        



    }

}