#include<bits/stdc++.h>
using namespace std;

void sol(int n , int sum){
    if(n==1){
        cout<<sum<<" ";
        return ;
    }
    else{    
        cout<<0;
    return sol(n-1 , sum);}
}


int main(){
    int n;
    cin>>n;
    cout<<1;
    n--;
    sol(n,9);

    return 0;
}