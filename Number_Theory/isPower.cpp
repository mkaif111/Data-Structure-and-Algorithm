#include<bits/stdc++.h>
using namespace std;

int check(int A){
    
    if(A==1)
    return 1;
    for(int i=2;i<=sqrt(A);i++)
    {
        long long int num=1;
        while(true)
        {
            num=num*i;
            cout<<num<<endl;
            if(num==A)
            return 1;
            
            else if(num>A)
            break;
        }
    }
    
    return 0;
}

int main(){
    int n; cin>>n;
    cout<<check(n)<<endl;
}