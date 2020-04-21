#include<bits/stdc++.h>
using namespace std;



int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int count = n/2;
        int sum_even=0;
        if(count%2==0){
            cout<<"YES"<<endl;
        for(int i=1;i<=count;i++){
            cout<<i*2<<" ";
            sum_even+=2*i;
        }
        int sum_odd = 0;
        for(int i=1;i<n-1;i+=2){
            cout<<i<<" ";
            sum_odd+=i;
        }
        cout<<sum_even-sum_odd<<endl;
        }
        else
            cout<<"NO"<<endl;
    }


}