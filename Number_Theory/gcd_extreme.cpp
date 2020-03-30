#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846
 
typedef long long ll ;
typedef unsigned long long ull ;


int phi[1000000+10] ;
ll S[1000000+10] ;

void pre_calculation()
{
    phi[1] = 1 ;
    for(int i=2;i<=1000000;i++)
    {
        if(phi[i]==0)
        {
            phi[i] = i-1 ;
            for(int j=i+i;j<=1000000;j+=i)
            {
                if(phi[j]==0) phi[j] = j ;
                phi[j] = phi[j] - phi[j]/i ;
            }
        }
    }
 
    for(int i=1;i<=1000000;i++)
    {
        for(int j=i+i;j<=1000000;j+=i)
        {
            S[j] = S[j] + (ll) (i*phi[j/i]);
        }
    }
 
    for(int i=1;i<=1000000;i++) S[i] = S[i] + S[i-1] ;
}

int main()
{
    
    pre_calculation();
    int n ;
    while(scanf("%d",&n)==1&&n!=0) printf("%lld\n",S[n]);
    return 0;
}