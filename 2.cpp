#include<bits/stdc++.h>
using namespace std;

#define ll long long int


int main(){

    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];

        }

        string ans = "yes";
        for(int i=0;i+k<n;i++)
        {
            if(arr[i]>arr[i+k]){
                
              

                    swap(arr[i],arr[i+k]);

                    
                

                
                
            }
            
        }


        for(int i=0;i<n-1;i++){
            // cout<<arr[i]<<" ";
            if(arr[i]>arr[i+1]){
                ans="no";
                break;
            }
        }
        // cout<<arr[n-1];
        cout<<endl;
            


        cout<<ans<<endl; 
    }
}