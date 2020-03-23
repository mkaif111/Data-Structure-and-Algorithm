#include<iostream>
using namespace std;

#define MAX 1000001

int* sieve(){
    int* prime = new int[MAX];
    
    for(int i=0;i<=MAX;i++){
        prime[i]=0;
    }
    
    for(int i=2;i<=MAX;i++){
        if(prime[i]==0)
        {
            for(int j=2*i;j<=MAX;j+=i){
                prime[j]++;
            }
            
            prime[i]=1;
        }
    }
    
    
    return prime;
}

int** table_generate(int* prime){
    int** table = new int*[11];
    
    for(int i=0;i<=10;i++){
        table[i] = new int[MAX];
        for(int j=0;j<=MAX;j++){
            table[i][j] = 0;
            
        }
    }
    
    for(int i=0;i<=10;i++){
        for(int j=1;j<=MAX;j++)
        {
            if(prime[j]==i)
            {
                
                table[i][j] = table[i][j-1]+1;
            }
            
            else
            {
                table[i][j] = table[i][j-1];
            }
        }
    }
    
    return table;
}

int main(){
	// Write your code here
    
    int* prime = sieve();
    int** table = table_generate(prime);
    
    int t;
    cin>>t;
    
    while(t--){
        
        int a,b,n;
        cin>>a>>b>>n;
        
       
        cout<<table[n][b]-table[n][a-1]<<endl;
        
        
        
        
    }
    
    delete prime;
    delete table;
	return 0;
}