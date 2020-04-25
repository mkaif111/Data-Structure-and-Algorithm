#include<bits/stdc++.h>
using namespace std;


int main(){

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int val = 1;
        for(int j=1;j<=n;j++){
            if(j<=i){
                cout<<val<<"\t";
                val = (j<n)?val+1:val-1;
            }
            else{
                cout<<"\t";
                if(j==n){
                    val--;
                }
            }
        }
        
        for(int j=n-1;j>0;j--){
            if(j<=i){
                cout<<val<<"\t";
                val--;
            }
            else{
                cout<<"\t";
            }
        }
        cout<<endl;
    }

}