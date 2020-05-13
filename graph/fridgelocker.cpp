#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int sum=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            sum+=x;
        }
        if(n==2 || m<n){
            cout<<-1<<endl;
        }
        else{
            cout<<2*sum<<endl;
            for(int i=1;i<n;i++){
                cout<<i<<" "<<i+1<<endl;

            }
            cout<<n<<" "<<1<<endl;
        }

    }// while endhere
}