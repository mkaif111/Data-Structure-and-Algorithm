#include<bits/stdc++.h>
using namespace std;

bool isPossible(long long n,long long mid){

    long long sum = 0;
    long long curr=n;
    while(curr>0){
        sum = sum + min(curr,mid);
        curr = curr - mid;
        curr -= curr/10;
    }

    if(2*sum>=n){return true;}
    else{return false;}
}

long long find_k(long long n){
    long long start = 1;
    long long end = n;
    long long ans =n;
    while(start<=end){
    long long mid = start+ (end-start)/2 ;

    if (isPossible(n,mid)){
        if(mid<=ans){
            ans = mid;
        }
        end = mid-1;

    }
    else{
        start = mid+1;
    }

    }

    return ans;

}

int main()
{
    long long n;
    cin>>n;



    long long k = find_k(n);
    cout<<k<<endl;

	return 0;
}
