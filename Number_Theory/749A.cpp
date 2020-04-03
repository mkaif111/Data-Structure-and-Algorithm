#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    if (n%2!=0){
        cout<<(n-1)/2<<endl;
        for(int i=2;i<(n-1);i+=2){
            cout<<2<<" ";
        }
        cout<<3<<endl;
    }
    else{
        cout<<n/2<<endl;
        for(int i=2;i<=n;i+=2){
            cout<<2<<" ";
        }
    }
}