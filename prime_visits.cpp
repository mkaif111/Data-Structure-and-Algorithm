#include<bits/stdc++.h>
using namespace std;


int prime_n(int a , int n)
{

   int count = 0;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=a; p*p<=n; p++)
    {

        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }


    for (int p=a; p<=n; p++){
       if (!prime[p])
          { count++; cout<<p<<endl; }
        }

	return count;
}
int main() {

	int t;
	cin>>t;

	while(t--){
		int  a,b;
		cin>>a>>b;



		cout<<prime_n(a,b)<<endl;
	}
}
