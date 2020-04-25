#include<bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin>>t;

    while(t--){
        int n,s;
        cin>>n>>s;
      
        int a[n];
        int b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
         for(int i=0;i<n;i++){
            cin>>b[i];
        }

        int f[n],d[n];
        int m,n_;
        m=n_=0;
        for(int i=0;i<n;i++){
            if(b[i]==1){
                f[m++]=(a[i]);

            }
            else{
                d[n_++]=(a[i]);
            }
        }

        sort(f,f+m);
        sort(d,d+n_);

        if(f[0]+d[0]+s<=100 && (m>0 && n_>0)){
            cout<<"yes"<<endl;

        }
        else{
            cout<<"no"<<endl;
        }
        
    }
}