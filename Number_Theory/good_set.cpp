#include<iostream>
using namespace std;

typedef long long int ll;
#define MAX 750001
#define MOD 1000000007

ll sieve(int* arr,int n){
    
    int *prime = new int[MAX];
    
    for(int i=0;i<MAX;i++){
        prime[i]=0;
    }
    
    for(int i=0;i<n;i++){
        
        int index = arr[i];
        prime[index] = 1;   
    }
    
     for(int i=1;i<MAX;i++){
         
        if(prime[i]>0)
        {
            
            for(int j=2*i;j<=MAX;j+=i)
            {
                if(prime[j]>0)
                {
                    prime[j] = (prime[j]%MOD+prime[i]%MOD)%MOD;
                }
                
                
            }
                  
        }
    }
    
    ll sum=0;
    
    for(int i=0;i<n;i++){
        sum+=(prime[arr[i]])%MOD;
    }
    
    
    delete prime;
    
    return sum%MOD;
    
    
}

int main(){
	// Write your code here
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        cout<<sieve(arr,n)<<endl;
        delete arr;
    }
    
    
	return 0;
}
