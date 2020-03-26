#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007


// Simple Recursive using Even/odd Method Time Complexity is logB
int power_num(int a, int b){
    if (b==0){ return 1;}
    if (b==1){ return a;}

    if(b%2==0){
        int val = power_num(a,b/2)%MOD;

        return (val*val)%MOD;
    }

    return (a*power_num(a,b-1))%MOD;
}

int power_num_iter(int a, int b){

    long long int  ans = 1;

    while(b!=0)
    {
        if(b&1==1){
            ans*=a%MOD;
        }
    
    a = (a*a)%MOD;
    b = b/2; // binary--> if it is 1001 it become --> 100 right shift basically
}


    return ans%MOD;
}

int main(){


    int num , power;
    cin>>num>>power;

    cout<<power_num(num,power)<<endl;

    cout<<power_num_iter(num,power)<<endl;

}