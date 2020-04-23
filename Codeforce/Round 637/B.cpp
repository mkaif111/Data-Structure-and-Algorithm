#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){

    int t;
    cin>>t;

    while(t--){

        int n,m;
        cin>>n>>m;

        ll arr[n],prefix_sum[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        prefix_sum[0]=0;
        int temp[n];
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                temp[i] = 1;
            }
            else temp[i]=0;

        }
        for(int i=1;i<n-1;i++){
            prefix_sum[i] = prefix_sum[i-1]+temp[i];
        }

        prefix_sum[n-1] = 0;

        int lowest = 0;
        ll pieces = INT_MIN;
        // for(int i=0;i<n;i++){
        //     cout<<prefix_sum[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0;i+m-1<n;i++){
            int inx = i;
            // if(i!=0) inx--;
            ll p = prefix_sum[i+m-2] - prefix_sum[i];
            if(p>pieces){
                pieces = p;
                lowest = i+1;
            }
        }

        cout<<pieces+1<<" "<<lowest<<endl;
        

    }
}