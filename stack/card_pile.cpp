#include<iostream>
#include<stack>
#include<vector>
using namespace std;
#define MAX 100001


typedef long long int ll;

ll prime[MAX];
// vector<int> sieve(){

// 	int *arr = new int[N];
	

// 	for(int i=2;i<=N;i++){
// 		int ele = arr[i];
// 		if(ele==0){
// 			for(int j=2*i;j*j<=N; j+=i){
// 				arr[j] = i;
// 			}
// 		}
// 	}
// 	vector<int> v;
// 	v.push_back(2);
// 	for(int i=3;i<=N;i+=2){
// 		int ele = arr[i];
// 		if(ele)
// 			v.push_back(i);
// 	}

// 	return v;


	
// }

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
    vector<int> primes;
    for(ll i=2;i<=MAX;i++){
        if(prime[i]==i){
            primes.push_back((int)i);
        }
    }

	
	int n , q;
	cin>>n>>q;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

	vector<stack<int>>B;
	vector<stack<int>>A;
	stack<int>A0;
	for(int i=0;i<n;i++)
	{
		A0.push(arr[i]);
	}
	A.push_back(A0);
	stack<int>B0;
	B.push_back(B0);
	for(int i=1;i<=q;i++)
	{
		stack<int> A_i = A[i-1];

		stack<int>Ai;
		stack<int>Bi;
		int prime_no = primes[i-1];
		while(A_i.empty()==false)
		{
			if(A_i.top()%prime_no == 0)
			{
				Bi.push(A_i.top());
				A_i.pop();
			}
			else
			{
				Ai.push(A_i.top());
				A_i.pop();
			}
		}

		A.push_back(Ai);
		B.push_back(Bi);
		

	}
	// cout<<B.size()<<endl;
	for(int i=1;i<B.size();i++)
	{
		stack<int>Ai = A[i];
		stack<int>Bi = B[i];

		while(!Bi.empty()){
			cout<<Bi.top()<<endl;
			Bi.pop();
		}

		while(!Ai.empty()){
			cout<<Ai.top()<<endl;
			Ai.pop();
		}
		
	}
	return 0;
}