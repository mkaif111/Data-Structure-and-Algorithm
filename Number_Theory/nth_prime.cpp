#include<iostream>
#include<vector>
using namespace std;
#define MAX 100000001


typedef long long int ll;

ll prime[MAX];


int main() {

    for(ll i=0;i<MAX;i++){
		prime[i]=1;
	}

	prime[0]=0;
	prime[1]=0;

    for(ll i = 2;i<=MAX;i++){
        if(prime[i]==1){
            for(ll j=i*i;j<=MAX;j+=i){
                prime[j]=0;
            }
        }
    }

  


    ll n;
    cin>>n;
    for(ll i=2;i<=MAX;i++){
        if(prime[i]==1){n--;}
        if(n==0){
            cout<<i<<endl;
            break;
        }
    }

	return 0;
}