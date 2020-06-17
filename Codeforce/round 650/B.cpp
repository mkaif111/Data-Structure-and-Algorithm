#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int count=0;
        int e=0;int o=0;
        for(int i=0;i<n;i++){
            if(i%2==0 and arr[i]%2==1)
                e++;
            else if(i%2==1 and arr[i]%2==0)
            {
                o++;
            }
            
        }
        // cout<<o<<" "<<e<<" "<<endl;
        
        if(e!=o){
            count=-1;
        }
        else if(e==o){
            count = e;
        }

        
        cout<<count<<endl;
    }
}