#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        int arr[27];
        for(int i=0;i<27;i++){
            arr[i]=0;
            
        }

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr[x]=arr[x]+1;
            // cout<<arr[x]<<" "<<x<<endl;

        }

        

        // cout<<"----------------"<<endl;

        sort(arr,arr+27,greater<int>());

        

        if (n==1){
            cout<<1<<endl;
        }

        else{
            int ans = arr[0]+arr[1];
            cout<<ans<<endl;
        }
    }
}