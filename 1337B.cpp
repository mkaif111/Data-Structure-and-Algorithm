#include<bits/stdc++.h>
using namespace std;

int void_a(int x , int n){
    if(n<=0)
        return x;
    if(n==1){
        return (x/2) + 10;
    }
    return void_a((x/2) + 10 , n-1);
}

int main(){

    int t;
    cin>>t;

    while(t--){

        int x , m , n;
        cin>>x>>n>>m;

        int y = void_a(x,n)-m*10;

        if(x-m*10<=0 || y<=0)
            cout<<"yes"<<endl;
        else
        {
            cout<<"no"<<endl;
        }
        


    }
}