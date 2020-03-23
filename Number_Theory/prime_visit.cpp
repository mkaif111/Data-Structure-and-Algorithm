#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000001
typedef long long int ll;

int* sieve(){
    
	int* primes=new int[MAX];
   
    for(int i=0;i<=MAX;i++){
        primes[i]=1;
    }  

    

    primes[0] = 0;
    primes[1] = 0;
	
    
	  for(int i=2;i<=MAX;i++){
        if(primes[i]==1)
        {
            for(int j=2*i;j<=MAX;j+=i){
                primes[j]=0;
            }
            
           
        }
    }
 
	int* prefix_sum=new int[MAX];
    prefix_sum[0] =0;
	for(int i=1;i<MAX;i++){
		prefix_sum[i]=prefix_sum[i-1]+primes[i];
	}
   

    delete primes;
	
	return prefix_sum;

}


int main() {

    
	int* prime = sieve();
    

	int t;
	cin>>t;

	while(t--){
		int a,b;
		cin>>a>>b;

		cout<<prime[b]-prime[a-1]<<endl;
	}
	return 0;
}