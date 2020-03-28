#include<iostream>
#include<cstring>
using namespace std;

#define ll long long int
#define mod 1000000007

void multiply(ll A[2][2],ll M[2][2]){

	ll firstValue = (A[0][0] * M[0][0] + A[0][1] * M[1][0])%mod;
	ll secondValue = (A[0][0] * M[0][1] + A[0][1] * M[1][1])%mod;
	ll thirdValue = (A[1][0] * M[0][0] + A[1][1] * M[1][0])%mod;
	ll fourthValue = (A[1][0] * M[0][1] + A[1][1] * M[1][1])%mod;

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
		return n ;
	}
	ll A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	// Write your code here
    
    ll sum = 0;
    
    for(ll i=m;i<=n;i++){
        sum+=getFibonacci(i)%mod;
    }
    return sum%mod;
   
}

int main()
{
    unsigned long long m,n;
    cin>>m>>n;
	cout<<fiboSum(m,n);
    return 0;
}
