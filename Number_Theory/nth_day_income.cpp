#include<iostream>
using namespace std;

#define ll long long int
#define mod 1000000007

ll pow_mod(ll a,ll b,ll m)
{
 ll x=1,y=a;
 while(b>0)
 {
  	if(b & 1)
   	{
	x=(x*y)%m;
		   }

  y=(y*y)%m;

  b>>=1;
 }
 return x;
}


void multiply(ll A[2][2],ll M[2][2]){

	ll firstValue = (A[0][0] * M[0][0] + A[0][1] * M[1][0])%(mod-1);
	ll secondValue = (A[0][0] * M[0][1] + A[0][1] * M[1][1])%(mod-1);
	ll thirdValue = (A[1][0] * M[0][0] + A[1][1] * M[1][0])%(mod-1);
	ll fourthValue = (A[1][0] * M[0][1] + A[1][1] * M[1][1])%(mod-1);

	A[0][0] =firstValue;
	A[0][1] = secondValue;
	A[1][0] = thirdValue;
	A[1][1] = fourthValue;
	
}
void power(ll A[2][2],ll n){
	if(n==1){
		return;
	}
	power(A,n/2);
	multiply(A,A);
	if(n%2 !=0){
		ll F[2][2] = {{1,1},{1,0}};
		multiply(A,F);
	}
}
ll getFibonacci(ll n){
	if(n==0 || n==1){
		return n;
	}
	ll A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}

ll sol(ll n,ll f1,ll f2){

	ll power_b = getFibonacci(n);
	ll power_a = getFibonacci(n-1);

	ll b = pow_mod(f2+1,power_b,mod);
	ll a = pow_mod(f1+1,power_a,mod);

	return (a%mod)*(b%mod) - 1;



    
}



int main(){

    int t;
    cin>>t;

    while(t--){
        ll f1,f2, n;
        cin>>f1>>f2>>n;

        cout<<sol(n,f1,f2)<<endl;
    }
}