#include<iostream>
using namespace std;

int main()
{
	long long int n,a,b;
	cin>>n;
	if(n%2==0){
		a=(n/2)*(n/2)-1;
		b=(n/2)*(n/2)+1;
	}
	else{
		b=(((n+1)/2)*((n+1)/2))+(((n-1)/2)*((n-1)/2));
		a=((n+1)*(n-1))/2;
	}
	if(a>2 and b>2){cout<<a<<" "<<b;}
	else{cout<<"-1";}
	return 0;
}