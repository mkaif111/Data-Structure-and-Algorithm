#include <iostream>
using namespace std;

long long gcd(long long int a,long long int b){
    
    return (b==0)?a:gcd(b,a%b);
}
void func(long long n)
{
	// Write your code here
    
    
    long long int sum=0;
    for(long long int i=1;i<=n;i++){
        
        sum+=(i*n)/gcd(n,i);
        
    }
    
    cout<<sum<<endl;
    
}

               
 
int main()
{ 
    cout<<gcd(657,963)<<endl;
    // long long n;
    // cin>>n;

	// func(n);
    return 0;
}