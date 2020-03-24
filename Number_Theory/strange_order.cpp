#include<bits/stdc++.h>
using namespace std;

#define MAX 2000001

int main(){


    int* sieve = new int[MAX];

    for(int i=0;i<=MAX;i++) sieve[i]=i;

    for(int i=2;i*i<=MAX;i++){
        for(int j=i*i;j<=MAX;j+=i){
            if(sieve[j]>i)
                sieve[j]=i;
        }
    }




    int n,k=0;
    cin>>n;

    int* ans = new int[n];
    for(int i=0;i<n;i++){
        ans[i] = 0;

    }
    bool* marked = new bool[n+1];

    for(int i=0;i<=n;i++){
        marked[i]=false;
    }

    for(int i=n;i>=1;i--){
        if(!marked[i]){
            int prime = sieve[i];
            int x = i;
            vector<int> v;
            marked[i] = true;
            v.push_back(i);

            while(x!=1)
            {
                for(int j=i-prime;j>=1;j-=prime){
                    if(!marked[j]){
                        marked[j]=true;
                        v.push_back(j);
                    }
                }

                while(x%prime==0){
                    x = x/prime;
                }

                // next smallest prime factor
                prime = sieve[x];

            }

            sort(v.begin(),v.end(),greater<int>());

            for(int j=0;j<v.size();j++){
                ans[k]=v[j];
                k++;
            }
        }
    }
    ans[n-1]=1;

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

    cout<<endl;


}