#include<iostream>
using namespace std;

#define ll long long int


void multiply(ll A[2][2],ll [2][2]){

	ll firstValue = A[0][0] * M[0][0] + A[0][1] * M[1][0];
	ll secondValue = A[0][0] * M[0][1] + A[0][1] * M[1][1];
	ll thirdValue = A[1][0] * M[0][0] + A[1][1] * M[1][0];
	ll fourthValue = A[1][0] * M[0][1] + A[1][1] * M[1][1];

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
int getFibonacci(int n){
	if(n==0 || n==1){
		return n;
	}
	ll A[2][2] = {{1,1},{1,0}};
	power(A,n-1);
	return A[0][0];
}
int main(){
	int n;
	cin >> n;
	cout << getFibonacci(n)<<endl;
	return 0;
}